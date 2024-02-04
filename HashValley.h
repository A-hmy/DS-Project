#pragma once
#include<vector>
#include<list>
#include"valley.h"
using namespace std;
class HashValley
{
private:
	vector<list<valley*>> hashTable;
	int sizeHashTable;
public:
	HashValley();
	int HashFunction(string MainP);
	void insert(valley* MainP);
	valley* search(string MainP);
	void Deleted(valley com);
};

