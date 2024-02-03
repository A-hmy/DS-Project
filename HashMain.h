#pragma once
#include<vector>
#include<list>
#include<iostream>
#include"MainBranchClass.h"
#include <set>
using namespace std;
class HashMain
{
private:
	vector<list<MainBranchClass*>> hashTable;
	int sizeHashTable;
	vector<MainBranchClass>ListNumberOfBranches;
	set<int>FullIndex;
	void numberOfbranch();
	void merge(int begin, int end, int mid);
	void mergeSort(int const begin, int const end);
public:
	HashMain();
	int HashFunction(string MainP);
	void insert(MainBranchClass* MainP);
	MainBranchClass* search(string MainP);
	MainBranchClass mostBranches();
};
