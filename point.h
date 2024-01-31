#pragma once
class point
{
private:
	float x;
	float y;
public:
	point(float X = 0, float Y = 0);
	float getX();
	float getY();
	void setX(float X);
	void setY(float Y);
};

