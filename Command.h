#pragma once
#include<iostream>
#include"Branch.h"
#include"valley.h"
class Command
{
private:
	string NameCommand;
	Branch ExecuteNode;
	valley ExecuteValley;
	int numberOfCommand;
public:
	Command();
	Command(string name, Branch Br ,int num);
	Command(string name, valley Vall, int num);
	string getName();
	Branch getExecuteNode();
	valley getExecuteValley();
	int getNumberOfCommand();
	void setNameCommand(string Name);
	void setExecuteNode(Branch node);
	void setnumberOfCommand(int num);
};

