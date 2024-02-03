#pragma once
#include<iostream>
#include"Branch.h"
class Command
{
private:
	string NameCommand;
	Branch ExecuteNode;
	int numberOfCommand;
public:
	string getName();
	Branch getExecuteNode();
	int getNumberOfCommand();
};

