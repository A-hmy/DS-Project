#include"HashMain.h"

HashMain::HashMain()
{
	sizeHashTable = 41;
	hashTable.resize(41);
}

int HashMain::HashFunction(string MainP)
{
	int sum = 0;
	for (char c : MainP) {
		sum += (int)(c);
	}
	return sum % sizeHashTable;
}

void HashMain::insert(MainBranchClass* MainP)
{
	int index = HashFunction(MainP->getName());
	hashTable[index].push_back(MainP);
}

MainBranchClass* HashMain::search(string MainP)
{
	if (!hashTable.empty()) {
		int index = HashFunction(MainP);
		if (index < hashTable.size()) {
			for (auto x : hashTable[index]) {
				if (x->getName() == MainP) {
					return x;
				}
			}
		}
	}
	return NULL;
}




