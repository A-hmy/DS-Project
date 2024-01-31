#include "MainBranchClass.h"

MainBranchClass::MainBranchClass(string Name, float x, float y)
{
	name = Name;
	coordinate.setX(x);
	coordinate.setY(y);
}

void MainBranchClass::setBranch(Branch branch)
{
	Branchs.push_back(branch);
}
