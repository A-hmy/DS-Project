#pragma once
#include<iostream>
#include"point.h"
using namespace std;
class Branch
{
private:
	string name;
	point coordinate;
	string NameMainBranch;
public:
	Branch(string Name = 0, float X = 0, float Y = 0, string NameMain = 0);
};

