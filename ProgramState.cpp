#include "ProgramState.h"

ProgramState::ProgramState()
{
	SizeHash = 41;
	HashTableCommand.resize(41);
}
int ProgramState::HashFunction(int numberOfCommand)
{
	return numberOfCommand% SizeHash;
}
void ProgramState::insert(Command* com)
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
void ProgramState::Deleted(Command com) {
	int index = HashFunction(com.getNumberOfCommand());
	for (auto it = HashTableCommand[index].begin(); it != HashTableCommand[index].end(); ++it) {
		if ((*it)->getNumberOfCommand() == com.getNumberOfCommand()) {
			HashTableCommand[index].erase(it);
			break;
		}
	}
}

