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
	bool main;//Main branch:1 
public:
	Branch();
	Branch(string Name, float X , float Y , string NameMain,bool Main );
	bool getMainFlag();
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

