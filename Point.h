#pragma once

#include <math.h>
#include "Vector2.h"

struct Point
{
	Point(int x, int y) : X(x), Y(y) {}
	Point(Vector2 vec) : X(round(vec.X)), Y(round(vec.Y)) {}

	int X;
	int Y;
};