#include "Command.h"

string Command::getName()
{
	return NameCommand;
}

Branch Command::getExecuteNode()
{
	return ExecuteNode;
}

int Command::getNumberOfCommand()
{
	return numberOfCommand;
}
