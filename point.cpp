#include "point.h"

point::point(float X, float Y)
{
	x = X;
	y = Y;
}

float point::getX()
{
	return x;
}

float point::getY()
{
	return y;
}

void point::setX(float X)
{
	x = X;
}

void point::setY(float Y)
{
	y = Y;
}


