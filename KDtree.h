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
struct DistanceNode {
	Node* node;
	double distance;

	DistanceNode(Node* n, double d) : node(n), distance(d) {}
	bool operator<(const DistanceNode& other) const {
		return distance < other.distance;
	}
};

class KDtree {
private:
	Node* root;
	vector<point>nodes;//all node in my tree
	double calculateDistance(const point p1, const point p2);
public:
	KDtree() : root(nullptr) {}

	vector<Node*> findClosestNodes1(const point& target, int k);
	

	Node* newNode(float X, float Y);

	bool search(float X, float Y);

	void buildtree();

	void insert(point newPoint);
private:
	void findClosestNodes(Node* current, const point target, int depth, int k,
		vector<DistanceNode>& result);

	bool arePointsSame(point point1, point point2);

	bool searchRec(Node* r, float X, float Y, unsigned depth);

	Node* buildBalancedRec(int begin, int end, unsigned depth);

	void merge(int begine, int end, int mid, int Condition);

	void mergeSort(int const begin, int const end, int Condition);


};
