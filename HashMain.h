#pragma once
#include<vector>
#include<list>
#include<iostream>
#include"MainBranchClass.h"
using namespace std;
class HashMain
{
private:
	vector<list<MainBranchClass*>> hashTable;
	int sizeHashTable;
public:
	HashMain();
	int HashFunction(string MainP);
	void insert(MainBranchClass* MainP);
	MainBranchClass* search(string MainP);
};

