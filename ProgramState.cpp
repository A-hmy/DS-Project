#include "ProgramState.h"

ProgramState::ProgramState()
{
	NumberOfCommand = 0;
}
int ProgramState::HashFunction(int numberOfCommand)
{
	return numberOfCommand - 1;
}
void ProgramState::insert(Command*com)
{
	int index = HashFunction(com->getNumberOfCommand());
	HashTableCommand[index].push_back(com);
}
Command* ProgramState::search(int numberOfCommand)
{
	if (!HashTableCommand.empty()) {
		int index = HashFunction(numberOfCommand);
		if (index < HashTableCommand.size()) {
			for (auto x : HashTableCommand[index]) {
				if (x->getNumberOfCommand() == numberOfCommand) {
					return x;
				}
			}
		}
	}
	return NULL;
}

