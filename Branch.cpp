#include "Branch.h"


Branch::Branch()
{
	name = " ";
	coordinate.setX(0);
	coordinate.setY(0);
	NameMainBranch = " ";
	main = 0;
}

Branch::Branch(string Name, float X, float Y, string NameMain,bool Main)
{
	name = Name;
	coordinate.setX(X);
	coordinate.setY(Y);
	NameMainBranch = NameMain;
	main = Main;
}

Branch::Branch(const Branch& other)
{
	name = other.name;
	coordinate = other.coordinate;
	NameMainBranch = other.NameMainBranch;
	main = other.main;
}

bool Branch::getMainFlag()
{
	return main;
}

string Branch::getName()
{
	return name;
}

point Branch::getCoordinate()
{
	return coordinate;
}

string Branch::getNameMainBranch()
{
	return NameMainBranch;
}

void Branch::setName(string Name)
{
	name = Name;
}

void Branch::setCoordinate(point coor)
{
	coordinate.setX(coor.getX());
	coordinate.setY(coor.getY());
}

void Branch::setNameMainBranch(string NameMain)
{
	NameMainBranch = NameMain;
}

Branch& Branch::operator=(const Branch& branch)
{
	if (this != &branch)
	{
		name = branch.name;
		coordinate = branch.coordinate;
		NameMainBranch = branch.NameMainBranch;
		main = branch.main;
	}
	return *this;
}


bool Branch::operator==(const Branch& branch)const
{
	if (name == branch.name && coordinate == branch.coordinate && NameMainBranch == branch.NameMainBranch)
		return 1;
	else
		return 0;

}


