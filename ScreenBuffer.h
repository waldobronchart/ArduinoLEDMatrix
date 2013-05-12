#pragma once

class ScreenBuffer
{
public:
	ScreenBuffer(int width, int height);
	~ScreenBuffer(void);

	static ScreenBuffer* GetInstance();
	
	void SetupRowPins(int dataPin, int latchPin, int clockPin);
	void SetupColumnPins(int dataPin, int latchPin, int clockPin);

	int GetWidth();
	int GetHeight();

	void Write(int x, int y, int value);
	void ClearBuffer();
	void Sync();
	void SyncNext();
	void SyncRow(int row);

private:
	void ShiftZeros(int data, int latch, int clock, int numshifts);
	void ShiftSingle(int data, int latch, int clock, int value);

private:
	static ScreenBuffer* _instance;

	int _width, _height, _size;
	unsigned long* _buffer;
	int _currentRow;
	
	int _rowDataPin, _rowLatchPin, _rowClockPin;
	int _colDataPin, _colLatchPin, _colClockPin;
};

