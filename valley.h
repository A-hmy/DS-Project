#pragma once
#include<iostream>
#include"point.h"
using namespace std;
class valley
{
private:
	string name;
	point location[4];
public:
	valley();
	valley(string Name,point  Location[]);
	string getName();
	
};

