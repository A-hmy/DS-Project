#include "Branch.h"


Branch::Branch()
{
	name = " ";
	coordinate.setX(0);
	coordinate.setY(0);
	NameMainBranch = " ";
}

Branch::Branch(string Name, float X, float Y, string NameMain)
{
	name = Name;
	coordinate.setX(X);
	coordinate.setY(Y);
	NameMainBranch = NameMain;
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

Branch& Branch::operator=(Branch& branch)
{
	name = branch.name;
	coordinate = branch.coordinate;
	NameMainBranch = branch.NameMainBranch;
	return *this;
}

Branch::Branch(const Branch& other)
{
	// Assuming Coordinate, Name, and NameMain are appropriately copyable
	coordinate = other.coordinate;  // Assuming Coordinate has a copy constructor
	name = other.name;
	NameMainBranch = other.NameMainBranch;
	// If there are dynamically allocated resources, ensure to deep copy them
	// Example: resourcePtr = new ResourceType(*(other.resourcePtr));
}
