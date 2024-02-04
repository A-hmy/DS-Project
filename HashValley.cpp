#include "HashValley.h"

HashValley::HashValley()
{
	sizeHashTable = 41;
	hashTable.resize(41);
}
int HashValley::HashFunction(string Vall)
{
	int sum = 0;
	for (char c : Vall) {
		sum += (int)(c);
	}
	return sum % sizeHashTable;
}
void HashValley::insert(valley* Vall)
{
	int index = HashFunction(Vall->getName());
	hashTable[index].push_back(Vall);
}
valley* HashValley::search(string Vall)
{
	if (!hashTable.empty()) {
		int index = HashFunction(Vall);
		if (index < hashTable.size()) {
			for (auto x : hashTable[index]) {
				if (x->getName() == Vall) {
					return x;
				}
			}
		}
	}
	return NULL;
}
void HashValley::Deleted(valley Vall) {
	int index = HashFunction(Vall.getName());
	for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
		if ((*it)->getName() == Vall.getName()) {
			hashTable[index].erase(it);
			break;
		}
	}
}



