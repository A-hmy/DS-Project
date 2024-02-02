#pragma once
#include <iostream>
#include "point.h"
#include<vector>
#include<algorithm>
#include"Branch.h"
using namespace std;
struct Node {
	Branch pizzeria;
	Node* left;
	Node* right;
	Node();
	Node(Branch& P);
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
	vector<Branch>nodes;//all node in my tree
public:
	KDtree() : root(nullptr) {}

	Node* newNode(string Name, float X, float Y, string NameMain);//*

	bool search(float X, float Y);//*

	Branch searchBranch(float X, float Y);

	void buildtree();//*

	void insert(Branch newBranch);//*

	vector<Node*> findClosestNodes1(const point& target, int k);

	void DeleteP(point deleteBranch);
private:
	void findClosestNodes(Node* current, const point target, int depth, int k,
		vector<DistanceNode>& result);

	bool arePointsSame(point point1, point point2);//*

	bool searchRec(Node* r, float X, float Y, unsigned depth);//*

	Branch searchBranchRec(Node* r, float X, float Y, unsigned depth);//*

	Node* buildBalancedRec(int begin, int end, unsigned depth);//*

	void merge(int begine, int end, int mid, int Condition);

	void mergeSort(int const begin, int const end, int Condition);

	double calculateDistance(const point p1, const point p2);
};
