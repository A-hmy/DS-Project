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
	int NumberOfBranch; 
public:
	MainBranchClass(string Name,float x,float y);
	void setBranch(const Branch& branch);
	void removeBranch(point& branch);
	string getName();
	point getCordinate();
	void printBranch();
	void setName(string Name);
	void setCordinate(int x,int y);
	void AddNumberOfBranch();
	void ReduceNumberOfPencils();
	int getNumberOfBranch();
};

