#include "MainBranchClass.h"

MainBranchClass::MainBranchClass()
{
	name = "";
	coordinate.setX(0);
	coordinate.setY(0);
	NumberOfBranch = 0;
}

MainBranchClass::MainBranchClass(string Name, float x, float y)
{
	name = Name;
	coordinate.setX(x);
	coordinate.setY(y);
	NumberOfBranch = 0;
}

void MainBranchClass::setBranch(const Branch& branch)
{
	Branches.push_back(branch);
}

void MainBranchClass::removeBranch(point& branch)
{
	for (auto it = Branches.begin(); it != Branches.end(); ++it) {
		if ((*it).getCoordinate() == branch) {
			Branches.erase(it);
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
	cout << name << "\t\t\t\033[38;5;28mbranches:";
	for (auto it : Branches) {
		cout <<"\t\t\t\033[38;5;28mName:" << it.getName() << "Coordinate:" << it.getCoordinate();
	}
	cout << "\033[0m";
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

void MainBranchClass::ReduceNumberOfBeranch()
{
	NumberOfBranch--;
}

int MainBranchClass::getNumberOfBranch()
{
	return NumberOfBranch;
}

vector<Branch> MainBranchClass::getBranches()//==================
{
	return Branches;
}
 