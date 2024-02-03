#pragma once
#include<vector>
#include<list>
#include<iostream>
#include <set>
#include"Command.h"
class ProgramState
{
private:
	vector<list<Command*>> HashTableCommand;
	int NumberOfCommand;
public:
	ProgramState();
	int HashFunction(int numberOfCommand);
	void insert(Command* com);
	Command* search(int numberOfCommand);
};

