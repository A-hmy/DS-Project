#pragma once
#include <iostream>
#include "point.h"
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	point location;
	Node* left;
	Node* right;
	Node();
	Node(point P);
};

class KDtree {
private:
	Node* root;
	vector<point>nodes;//all node in my tree
public:
	KDtree() : root(nullptr) {}

	Node* newNode(float X, float Y);

	bool search(float X, float Y);

	void buildtree();

	void insert(point newPoint);
private:

	bool arePointsSame(point point1, point point2);

	bool searchRec(Node* r, float X, float Y, unsigned depth);

	Node* buildBalancedRec(int begin, int end, unsigned depth);

	void merge(int begine, int end, int mid, int Condition);

	void mergeSort(int const begin, int const end, int Condition);


};
