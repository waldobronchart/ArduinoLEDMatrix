#pragma once

#include "arduino.h"

class FontChar
{
public:
	// Constructors
	FontChar(void) {}
	FontChar(int width, int height, int offsetY, unsigned long data) :
		Width(width), Height(height), OffsetY(offsetY), _data(data)
	{
	}

	int GetValue(int x, int y)
	{
		return (_data >> (y * Width + x)) & 1;
	}

	int OffsetY;
	int Width, Height;

private:
	unsigned long _data;
};

class Font
{
public:
	Font(void);
	~Font(void) {}

	void MeasureString(const String& str, int& width, int& height, int spacing);

	FontChar** Chars;
	FontChar* UnsupportedChar;
};




