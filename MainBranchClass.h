#pragma once
#include<iostream>
#include<string>
#include"point.h"
#include"Branch.h"
#include<vector>
using namespace std;
class MainBranchClass
{
private:
	string name;
	point coordinate;
	vector<Branch> Branchs;
public:
	MainBranchClass(string Name,float x,float y);
	void setBranch(Branch branch);
};

