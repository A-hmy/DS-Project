#pragma once
#include<iostream>
class point
{
private:
	float x;
	float y;
public:
	friend std::ostream& operator<<(std::ostream& os, const point& p);
	point(float X = 0, float Y = 0);
	float getX();
	float getY();
	void setX(float X);
	void setY(float Y);
	void operator=(const point& point);
	bool operator==(const point& point)const;
	point(const point& other);
	friend std::istream& operator>>(std::istream& input, point& Point);
};

