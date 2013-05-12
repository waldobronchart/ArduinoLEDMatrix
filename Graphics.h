#pragma once

class ScreenBuffer;
#include <math.h>
#include "Point.h"
#include "Vector2.h"
#include "Font.h"

class String;

class Graphics
{
public:
	Graphics(ScreenBuffer* buffer, Font* font);
	~Graphics(void);

	static Graphics* GetInstance();

	void DrawRectangle(Vector2 pos, int width, int height, bool fill);
	void DrawLine(Vector2 v1, Vector2 v2);
	void DrawString(const String& str, Point pos, int spacing);
	void DrawChar(char c, Point pos);
	void DrawFontChar(FontChar* c, Point pos);

private:
	static Graphics* _instance;
	ScreenBuffer* _screenBuffer;
	Font* _font;
};

