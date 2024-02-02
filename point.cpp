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

void point::operator=(const point& point)
{
	x = point.x;
	y = point.y;
}

bool point::operator==(const point& point)const
{
	if (x == point.x && y == point.y)
		return 1;
	else
		return 0;
}

point::point(const point& other)
	: x(other.x), y(other.y) {}

std::ostream& operator<<(std::ostream& os, const point& p) {
	os << "(" << p.x << "," << p.y << ")" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& input, point& Point)
{

	std::cout << "Enter x-coordinate: ";
	input >> Point.x;

	std::cout << "Enter y-coordinate: ";
	input >> Point.y;

	return input;

}



