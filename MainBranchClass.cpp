#include "MainBranchClass.h"

MainBranchClass::MainBranchClass(string Name, float x, float y)
{
	name = Name;
	coordinate.setX(x);
	coordinate.setY(y);
	NumberOfBranch = 0;
}

void MainBranchClass::setBranch(const Branch& branch)
{
	Branchs.push_back(branch);
}

void MainBranchClass::removeBranch(point& branch)
{
	for (auto it = Branchs.begin(); it != Branchs.end(); ++it) {
		if ((*it).getCoordinate() == branch) {
			Branchs.erase(it);
			break;
		}
	}
}

string MainBranchClass::getName()
{
	return name;
}

point MainBranchClass::getCordinate()
{
	return coordinate;
}

void MainBranchClass::printBranch()
{
	cout << name << "branches:";
	for (auto it : Branchs) {
		cout <<"Name:" << it.getName()<<"Coordinate:" << it.getCoordinate();
	}
}

void MainBranchClass::setName(string Name)
{
	name = Name;
}

void MainBranchClass::setCordinate(int x, int y)
{
	coordinate.setX(x);
	coordinate.setY(y);
}

void MainBranchClass::AddNumberOfBranch()
{
	NumberOfBranch++;
}

void MainBranchClass::ReduceNumberOfPencils()
{
	NumberOfBranch--;
}

int MainBranchClass::getNumberOfBranch()
{
	return NumberOfBranch;
}
