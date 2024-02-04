#include "Command.h"

Command::Command()
{
	NameCommand = "";
	numberOfCommand = 0;
}

Command::Command(string name, Branch Br, int num)
{
	NameCommand = name;
	numberOfCommand = num;
	ExecuteNode = Br;
}

Command::Command(string name,valley vall, int num)
{
	NameCommand = name;
	ExecuteValley = vall;
	numberOfCommand = num;
}

string Command::getName()
{
	return NameCommand;
}

Branch Command::getExecuteNode()
{
	return ExecuteNode;
}

valley Command::getExecuteValley()
{
	return ExecuteValley;
}

int Command::getNumberOfCommand()
{
	return numberOfCommand;
}

void Command::setNameCommand(string Name)
{
	NameCommand = Name;
}

void Command::setExecuteNode(Branch node)
{
	ExecuteNode = node;
}

void Command::setnumberOfCommand(int num)
{
	numberOfCommand = num;
}
