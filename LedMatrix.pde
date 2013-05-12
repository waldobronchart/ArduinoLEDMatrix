#include <stdlib.h>
#include "cppfix.h";

#include "ScreenBuffer.h"
#include "Graphics.h"
#include "Vector2.h"
#include "Font.h"

#define ROW_DATA_PIN 2
#define ROW_LATCH_PIN 3
#define ROW_CLOCK_PIN 4
#define COL_DATA_PIN 8
#define COL_LATCH_PIN 9
#define COL_CLOCK_PIN 10

ScreenBuffer* screenBuffer;
Graphics* graphics;
Font* font;

unsigned long prevTime;
double deltaTime;

//#include "MemoryFree.h"

Vector2 pt(0, 1);
String str = "Why did the chicken cross the road??      WHY??";
Vector2 stringDim;
float width;

void setup()
{
	prevTime = millis();

	Serial.begin(9600);

	screenBuffer = new ScreenBuffer(8, 8);
	screenBuffer->SetupRowPins(ROW_DATA_PIN, ROW_LATCH_PIN, ROW_CLOCK_PIN);
	screenBuffer->SetupColumnPins(COL_DATA_PIN, COL_LATCH_PIN, COL_CLOCK_PIN);

	font = new Font();
	graphics = new Graphics(screenBuffer, font);

	//Serial.print("Free memory: ");
	//Serial.println(freeMemory());

	int width, height;
	font->MeasureString(str, width, height, 1);
	stringDim = Vector2(width, height);
}

void loop()
{
	// Calculate deltaTime
	unsigned long time = millis();
	deltaTime = double(time - prevTime) / 1000.0;
	prevTime = time;

	// Clear buffer
	screenBuffer->ClearBuffer();

	pt.X -= deltaTime * 15;
	if (pt.X < -stringDim.X)
		pt.X = 10;
	graphics->DrawString(str, Point(pt), 1);

	width += deltaTime * 5;
	if (width > 9)
		width = 0;
	graphics->DrawRectangle(Vector2(0, 0), width, 1, true);

	// Draw buffer to screeeen!
	screenBuffer->Sync();
	//screenBuffer->SyncNext();
	//screenBuffer->SyncRow(4);
}
