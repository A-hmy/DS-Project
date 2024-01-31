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
	Branch();
	Branch(string Name, float X , float Y , string NameMain );
	string getName();
	point getCoordinate();
	string getNameMainBranch();
	void setName(string Name);
	void setCoordinate(point coor);
	void setNameMainBranch(string NameMain);
	Branch& operator=(Branch& branch);
	Branch(const Branch& other);
	//~Branch();
};

