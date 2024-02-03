#include "KDtree.h"

Node* KDtree::newNode(string Name, float X, float Y, string NameMain)
{
	Node* temp = new Node;
	point* p = new point(X, X);
	temp->pizzeria.setCoordinate(*p);
	temp->pizzeria.setName(Name);
	temp->pizzeria.setNameMainBranch(NameMain);
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}


double KDtree::Distance(point p1, point p2) {
	double diffX = p1.getX() - p2.getX();
	double diffY = p1.getY() - p2.getY();
	return std::sqrt(diffX * diffX + diffY * diffY);
}


bool KDtree::search(float X, float Y)
{
	return searchRec(root, X, Y, 0);
}

Branch KDtree::searchBranch(float X, float Y)
{
	return searchBranchRec(root, X, Y, 0);
}

void KDtree::buildtree()
{
	root = buildBalancedRec(0, nodes.size() - 1, 0);
}

void KDtree::insert(Branch newBranch)
{
	nodes.push_back(newBranch);
	buildtree();
}

void KDtree::DeleteP(point deleteBranch)
{
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		if ((*it).getCoordinate() == deleteBranch) {
			nodes.erase(it);
			break;
		}
	}
	buildtree();
}

bool KDtree::arePointsSame(point point1, point point2)
{
	if (point1.getX() == point2.getX() && point1.getY() == point2.getY())
		return true;

	return false;
}

bool KDtree::searchRec(Node* r, float X, float Y, unsigned depth)
{
	point* checkPoint = new point(X, Y);
	if (r == NULL)
		return false;
	if (arePointsSame(r->pizzeria.getCoordinate(), *checkPoint))
		return true;
	unsigned cd = depth % 2;
	if (cd == 0) {
		if (checkPoint->getX() < r->pizzeria.getCoordinate().getX())
			return searchRec(r->left, checkPoint->getX(), checkPoint->getY(), depth + 1);
	}
	if (cd == 1) {
		if (checkPoint->getY() < r->pizzeria.getCoordinate().getY())
			return searchRec(r->left, checkPoint->getX(), checkPoint->getY(), depth + 1);
	}
	return searchRec(r->right, checkPoint->getX(), checkPoint->getY(), depth + 1);
}

Branch KDtree::searchBranchRec(Node* r, float X, float Y, unsigned depth)
{
	point* checkPoint = new point(X, Y);
	if (r != NULL) {
		if (arePointsSame(r->pizzeria.getCoordinate(), *checkPoint))
			return r->pizzeria;
		unsigned cd = depth % 2;
		if (cd == 0) {
			if (checkPoint->getX() < r->pizzeria.getCoordinate().getX())
				return searchBranchRec(r->left, checkPoint->getX(), checkPoint->getY(), depth + 1);
		}
		if (cd == 1) {
			if (checkPoint->getY() < r->pizzeria.getCoordinate().getY())
				return searchBranchRec(r->left, checkPoint->getX(), checkPoint->getY(), depth + 1);
		}
		return searchBranchRec(r->right, checkPoint->getX(), checkPoint->getY(), depth + 1);
	}
}

Node* KDtree::buildBalancedRec(int begin, int end, unsigned depth)
{
	if (begin > end) {
		return nullptr;
	}
	int comparator = depth % 2;
	mergeSort(begin, end, comparator);
	int medianPointIndex = begin + ((end - begin) / 2);
	Branch medianPointData = nodes[medianPointIndex];
	Node* nodeR = new Node(medianPointData);
	nodeR->left = buildBalancedRec(begin, medianPointIndex - 1, depth + 1);
	nodeR->right = buildBalancedRec(medianPointIndex + 1, end, depth + 1);
	return nodeR;
}

void KDtree::merge(int begin, int end, int mid, int Condition)
{
	int SizeArrayLeft = mid - begin + 1;
	int SizeArrayRight = end - mid;
	//cout << SizeArrayRight;
	std::vector<Branch> ArrayLeft;
	ArrayLeft.resize(SizeArrayLeft);
	//Branch ArrayLeft[100];
	std::vector<Branch> ArrayRight;
	ArrayRight.resize(SizeArrayRight);
	//Branch ArrayRight[100];

	for (int i = 0; i < SizeArrayLeft; i++)
		ArrayLeft[i] = nodes[begin + i];

	for (int i = 0; i < SizeArrayRight; i++)
		ArrayRight[i] = nodes[mid + 1 + i];

	int indexLeft = 0, indexRight = 0, indexVector = begin;

	while (indexLeft < SizeArrayLeft && indexRight < SizeArrayRight) {
		if (Condition) {
			if (ArrayLeft[indexLeft].getCoordinate().getY() < ArrayRight[indexRight].getCoordinate().getY()) {
				nodes[indexVector] = ArrayLeft[indexLeft];
				indexLeft++;
			}
			else {
				nodes[indexVector] = ArrayRight[indexRight];
				indexRight++;
			}
		}
		else {
			if (ArrayLeft[indexLeft].getCoordinate().getX() < ArrayRight[indexRight].getCoordinate().getX()) {
				nodes[indexVector] = ArrayLeft[indexLeft];
				indexLeft++;
			}
			else {
				nodes[indexVector] = ArrayRight[indexRight];
				indexRight++;
			}
		}
		indexVector++;
	}

	while (indexLeft < SizeArrayLeft) {
		nodes[indexVector] = ArrayLeft[indexLeft];
		indexLeft++;
		indexVector++;
	}

	while (indexRight < SizeArrayRight) {
		nodes[indexVector] = ArrayRight[indexRight];
		indexRight++;
		indexVector++;
	}
}

void KDtree::mergeSort(int const begin, int const end, int Condition)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort(begin, mid, Condition);
	mergeSort(mid + 1, end, Condition);
	merge(begin, end, mid, Condition);
}

Node::Node()
{
	left = NULL;
	right = NULL;
}

Node::Node(Branch& P)
	: pizzeria(P), left(nullptr), right(nullptr) {}


Node* KDtree::FindClosest(Node* current, point& target, int depth) {
	if (current == nullptr) {
		return nullptr;
	}

	int axis = depth % 2;
	Node* nextBranch = (axis == 0 && target.getX() < current->pizzeria.getCoordinate().getX() ||
		(axis == 1 && target.getY() < current->pizzeria.getCoordinate().getY())) ?
		current->left : current->right;
	Node* otherBranch = (axis == 0 && target.getX() < current->pizzeria.getCoordinate().getX() ||
		(axis == 1 && target.getY() < current->pizzeria.getCoordinate().getY())) ?
		current->right : current->left;

	Node* closest = FindClosest(nextBranch, target, depth + 1);

	double distance = Distance(current->pizzeria.getCoordinate(), target);
	double closestDistance = (closest != nullptr) ? Distance(closest->pizzeria.getCoordinate(), target) : std::numeric_limits<double>::max();


	if (distance < closestDistance) {
		closest = current;
	}

	if ((axis == 0 && abs(target.getX() - current->pizzeria.getCoordinate().getX()) < closestDistance) ||
		(axis == 1 && abs(target.getY() - current->pizzeria.getCoordinate().getY()) < closestDistance)) {
		Node* closestOtherBranch = FindClosest(otherBranch, target, depth + 1);
		if (closestOtherBranch != nullptr) {
			double otherBranchDistance = Distance(closestOtherBranch->pizzeria.getCoordinate(), target);
			if (otherBranchDistance < Distance(closest->pizzeria.getCoordinate(), target)) {
				closest = closestOtherBranch;
			}
		}
	}

	return closest;
}

Node* KDtree::FindClosest1(point& target) {
	return FindClosest(root, target, 0);
}


void KDtree::FindPointsInCircle(Node* current, point& target, float radius, vector<Branch>& result, int depth) {
	if (current == nullptr) {
		return;
	}


	int axis = depth % 2;
	Node* nextBranch = (axis == 0 && target.getX() < current->pizzeria.getCoordinate().getX()) ||
		(axis == 1 && target.getY() < current->pizzeria.getCoordinate().getY()) ?
		current->left : current->right;

	Node* otherBranch = (axis == 0 && target.getX() < current->pizzeria.getCoordinate().getX()) ||
		(axis == 1 && target.getY() < current->pizzeria.getCoordinate().getY()) ?
		current->right : current->left;

	FindPointsInCircle(nextBranch, target, radius, result, depth + 1);

	double distance = Distance(current->pizzeria.getCoordinate(), target);

	if (distance <= radius) {
		result.push_back(current->pizzeria);
	}


	if ((axis == 0 && abs(target.getX() - current->pizzeria.getCoordinate().getX()) < radius) ||
		(axis == 1 && abs(target.getY() - current->pizzeria.getCoordinate().getY()) < radius)) {
		FindPointsInCircle(otherBranch, target, radius, result, depth + 1);
	}
}

vector<Branch> KDtree::FindPointsInCircle1(point& target, float radius) {
	std::vector<Branch> result;
	FindPointsInCircle(root, target, radius, result, 0);
	return result;
}

bool KDtree::IsInsideToRectangle(point A, point B, point C, point D,point M) {
	int flag = 0;

	// Check if the ray from M along the positive x-axis intersects with each edge
	if ((A.getY() > M.getY()) != (B.getY() > M.getY()) && M.getX() < (B.getX() - A.getX()) * (M.getY() - A.getY()) / (B.getY() - A.getY()) + A.getX()) {
		++flag;
	}

	if ((B.getY() > M.getY()) != (C.getY() > M.getY()) && M.getX() < (C.getX() - B.getX()) * (M.getY() - B.getY()) / (C.getY() - B.getY()) + B.getX()) {
		++flag;
	}

	if ((C.getY() > M.getY()) != (D.getY() > M.getY()) && M.getX() < (D.getX() - C.getX()) * (M.getY() - C.getY()) / (D.getY() - C.getY()) + C.getX()) {
		++flag;
	}

	if ((D.getY() > M.getY()) != (A.getY() > M.getY()) && M.getX() < (A.getX() - D.getX()) * (M.getY() - D.getY()) / (A.getY() - D.getY()) + D.getX()) {
		++flag;
	}

	// If the number of intersections is odd, the point is inside the polygon
	return (flag % 2 == 1);
}




void KDtree::FindPointsInRectangle(point A, point B, point C, point D) {
	for (auto& point1 : nodes) {
		if (IsInsideToRectangle(A, B, C, D, point1.getCoordinate())) {
			cout << "\n" << point1.getName() << "   :        " <<  "("  << point1.getCoordinate().getX() << ", " << point1.getCoordinate().getY() << ")\n";
		}

	}
}