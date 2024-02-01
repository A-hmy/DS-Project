#include "valley.h"
valley::valley(string Name , float X1 , float Y1 , float X2 , float Y2 , float X3 , float Y3 , float X4, float Y4) {
	name = Name;
	point1.setX(X1);
	point1.setY(Y1);
	point2.setX(X2);
	point2.setY(Y2);
	point3.setX(X3);
	point3.setY(Y3);
	point4.setX(X4);
	point4.setY(Y4);
}
