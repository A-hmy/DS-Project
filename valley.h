#pragma once
#include<iostream>
#include"point.h"
using namespace std;
class valley
{
private:
	string name;
	point point1;
	point point2;
	point point3;
	point point4;
	
public:
	valley(string Name = 0, float X1 = 0, float Y1 = 0, float X2 = 0, float Y2 = 0, float X3 = 0, float Y3 = 0, float X4 = 0, float Y4 = 0);
};

