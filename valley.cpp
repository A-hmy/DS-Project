#include "valley.h"


valley::valley()
{
	point p(0, 0);
	name = "";
	for (int i = 0; i < 4; i++) {
		location[i] = p;
	}
}
valley::valley(string Name, point Location[])
{
	name = Name;
	for (int i = 0; i < 4; i++)
		location[i] = Location[i];
}

string valley::getName()
{
	return name;
}

point* valley::getPoint()
{
	return location;
}

valley& valley::operator=(const valley& vall)
{
	if (this != &vall)
	{
		name = vall.name;
		for (int i = 0; i < 4; i++)
			location[i] = vall.location[i];
	}
	return *this;
}