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

	Node* FindClosest1(point& target);

	vector<Branch> FindPointsInCircle1(point& target, float radius);

	void DeleteP(point deleteBranch);

	void setNodes(vector<Branch>Nodes);
private:

	void FindPointsInCircle(Node* current, point& target, float radius, std::vector<Branch>& result, int depth);

	Node* FindClosest(Node* current, point& target, int depth);

	bool arePointsSame(point point1, point point2);//*

	bool searchRec(Node* r, float X, float Y, unsigned depth);//*

	Branch searchBranchRec(Node* r, float X, float Y, unsigned depth);//*

	Node* buildBalancedRec(int begin, int end, unsigned depth);//*

	void merge(int begine, int end, int mid, int Condition);

	void mergeSort(int const begin, int const end, int Condition);

	double Distance(const point p1, const point p2);

	double calculateDistance(point p1, point p2);
};
