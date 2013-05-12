#include "ScreenBuffer.h"
#include "arduino.h"

ScreenBuffer* ScreenBuffer::_instance = 0;

ScreenBuffer::ScreenBuffer(int width, int height) : _width(width), _height(height), _size(width*height), _currentRow(0)
{
	_instance = this;

	_buffer = new unsigned long[height];
	ClearBuffer();
}

ScreenBuffer::~ScreenBuffer(void)
{
	_instance = 0;
	delete _buffer;
}

ScreenBuffer* ScreenBuffer::GetInstance()
{
	return _instance;
}

void ScreenBuffer::SetupRowPins(int dataPin, int latchPin, int clockPin)
{
	_rowDataPin = dataPin;
	_rowLatchPin = latchPin;
	_rowClockPin = clockPin;
	
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
}

void ScreenBuffer::SetupColumnPins(int dataPin, int latchPin, int clockPin)
{
	_colDataPin = dataPin;
	_colLatchPin = latchPin;
	_colClockPin = clockPin;
	
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
}

int ScreenBuffer::GetWidth()
{
	return _width;
}

int ScreenBuffer::GetHeight()
{
	return _height;
}

void ScreenBuffer::Write(int x, int y, int value)
{
	// Clip
	if (x < 0 || x > _width-1 || y < 0 || y > _height-1)
		return;

	if (value > 0)
	{
		_buffer[y] |= 1 << x;
		return;
	}

	_buffer[y] ^= 1 << x;
}

void ScreenBuffer::ClearBuffer()
{
	for (int i=0; i<_height; ++i)
	{
		_buffer[i] = 0;
	}
}

void ScreenBuffer::SyncNext()
{
	_currentRow++;
	if (_currentRow == _height)
		_currentRow = 0;

	SyncRow(_currentRow);
}

void ScreenBuffer::SyncRow(int row)
{
	// Clear column data in register before moving to next row
	ShiftZeros(_colDataPin, _colLatchPin, _colClockPin, _width);

	// Shift current row out (1 of all rows will be illuminated)
	ShiftSingle(_rowDataPin, _rowLatchPin, _rowClockPin, (row==0)?1:0);

	// Shift column data out
	digitalWrite(_colLatchPin, LOW);
	for (int col=0; col<_width; ++col)
	{
		digitalWrite(_colClockPin, LOW);

		int val = (_buffer[row] >> col) & 1;
		digitalWrite(_colDataPin, val);

		digitalWrite(_colClockPin, HIGH);
	}
	digitalWrite(_colLatchPin, HIGH);
}

void ScreenBuffer::Sync()
{
	// Row by row shifting, top to bottom
	for (int row=0; row<_height; ++row)
	{
		SyncRow(row);

		// Let it flow
		delayMicroseconds(500);
	}

	// Shift last bit out of the row
	ShiftSingle(_rowDataPin, _rowLatchPin, _rowClockPin, 0);
}

void ScreenBuffer::ShiftZeros(int data, int latch, int clock, int numshifts)
{
	digitalWrite(latch, LOW);
	digitalWrite(data, LOW);
	digitalWrite(clock, LOW);

	for (int i=0; i<numshifts; i++)
	{
		digitalWrite(clock, LOW);
		digitalWrite(data, LOW);
		digitalWrite(clock, HIGH);
	}

	digitalWrite(latch, HIGH);
}

void ScreenBuffer::ShiftSingle(int data, int latch, int clock, int value)
{
	digitalWrite(latch, LOW);
	digitalWrite(clock, LOW);
	digitalWrite(data, value);
	digitalWrite(clock, HIGH);
	digitalWrite(latch, HIGH);
}