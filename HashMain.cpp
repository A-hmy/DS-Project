#include"HashMain.h"

void HashMain::numberOfbranch()
{
	for (int i : FullIndex) {
		for (auto j : hashTable[i]) {
			ListNumberOfBranches.push_back(*j);
		}
	}
}

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
	FullIndex.insert(index);
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

void HashMain::merge(int begin, int end, int mid)
{
	int SizeArrayLeft = mid - begin + 1;
	int SizeArrayRight = end - mid;
	std::vector<MainBranchClass> ArrayLeft;
	ArrayLeft.resize(SizeArrayLeft);
	std::vector<MainBranchClass> ArrayRight;
	ArrayRight.resize(SizeArrayRight);
	for (int i = 0; i < SizeArrayLeft; i++)
		ArrayLeft[i] = ListNumberOfBranches[begin + i];

	for (int i = 0; i < SizeArrayRight; i++)
		ArrayRight[i] = ListNumberOfBranches[mid + 1 + i];

	int indexLeft = 0, indexRight = 0, indexVector = begin;

	while (indexLeft < SizeArrayLeft && indexRight < SizeArrayRight) {

		if (ArrayLeft[indexLeft].getNumberOfBranch() < ArrayRight[indexRight].getNumberOfBranch()) {
			ListNumberOfBranches[indexVector] = ArrayLeft[indexLeft];
			indexLeft++;
		}
		else {
			ListNumberOfBranches[indexVector] = ArrayRight[indexRight];
			indexRight++;
		}

		indexVector++;
	}

	while (indexLeft < SizeArrayLeft) {
		ListNumberOfBranches[indexVector] = ArrayLeft[indexLeft];
		indexLeft++;
		indexVector++;
	}

	while (indexRight < SizeArrayRight) {
		ListNumberOfBranches[indexVector] = ArrayRight[indexRight];
		indexRight++;
		indexVector++;
	}
}

void HashMain::mergeSort(int const begin, int const end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort(begin, mid);
	mergeSort(mid + 1, end);
	merge(begin, end, mid);
}

MainBranchClass HashMain::mostBranches() {
	numberOfbranch();
	mergeSort(0, ListNumberOfBranches.size() - 1);
	int size = ListNumberOfBranches.size() - 1;
	if (size >= 0) {
		return ListNumberOfBranches[size];
	}
}

void HashMain::Deleted(MainBranchClass Br) {
	int index = HashFunction(Br.getName());
	for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
		if ((*it)->getName() == Br.getName()&& (*it)->getCordinate()==Br.getCordinate()) {
			hashTable[index].erase(it);
			break;
		}
	}
}