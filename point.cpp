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

	std::cout << "\t\t\t\033[38;5;202mEnter x-coordinate:\033[0m";
	std::cout << "\033[38;5;220m";
	input >> Point.x;
	std::cout << "\033[0m";
	std::cout << "\t\t\t\033[38;5;202mEnter y-coordinate:\033[0m";
	std::cout << "\033[38;5;220m";
	input >> Point.y;
	std::cout << "\033[0m";
	return input;

}



