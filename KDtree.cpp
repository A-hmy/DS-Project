#include "KDtree.h"

Node* KDtree::newNode(float X, float Y)
{
	Node* temp = new Node;
	temp->location.setX(X);
	temp->location.setY(Y);
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

double KDtree::calculateDistance(point p1,point p2) {
		double diffX = p1.getX() - p2.getX();
		double diffY = p1.getY() - p2.getY();
		return std::sqrt(diffX * diffX + diffY * diffY);
}

bool KDtree::search(float X, float Y)
{
	return searchRec(root, X, Y, 0);
}

void KDtree::buildtree()
{
	root = buildBalancedRec(0, nodes.size() - 1, 0);
}

void KDtree::insert(point newPoint)
{
	nodes.push_back(newPoint);
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
	if (arePointsSame(r->location, *checkPoint))
		return true;
	unsigned cd = depth % 2;
	if (cd == 0) {
		if (checkPoint->getX() < r->location.getX())
			return searchRec(r->left, checkPoint->getX(), checkPoint->getY(), depth + 1);
	}
	if (cd == 1) {
		if (checkPoint->getY() < r->location.getY())
			return searchRec(r->left, checkPoint->getX(), checkPoint->getY(), depth + 1);
	}
	return searchRec(r->right, checkPoint->getX(), checkPoint->getY(), depth + 1);
}

Node* KDtree::buildBalancedRec(int begin, int end, unsigned depth)
{
	if (begin > end) {
		return nullptr;
	}

	// Calculate current dimension
	int comparator = depth % 2;

	mergeSort(begin, end, comparator);

	// Find the median point
	int medianPointIndex = begin + ((end - begin) / 2);
	point medianPointData = nodes[medianPointIndex];

	// Create a node and recursively build left and right subtrees
	Node* nodeR = new Node(medianPointData);
	nodeR->left = buildBalancedRec(begin, medianPointIndex - 1, depth + 1);
	nodeR->right = buildBalancedRec(medianPointIndex + 1, end, depth + 1);

	return nodeR;
}

void KDtree::merge(int begin, int end, int mid, int Condition)
{
	int SizeArrayLeft = mid - begin + 1;
	int SizeArrayRight = end - mid;
	point* ArrayLeft = new point[SizeArrayLeft];
	point* ArrayRight = new point[SizeArrayRight];
	for (int i = 0; i < SizeArrayLeft; i++)
		ArrayLeft[i] = nodes[begin + i];
	for (int i = 0; i < SizeArrayRight; i++)
		ArrayRight[i] = nodes[mid + 1 + i];
	int indexLeft = 0, indexRight = 0, indexVector = begin;
	while (indexLeft < SizeArrayLeft && indexRight < SizeArrayRight) {
		if (Condition && ArrayLeft[indexLeft].getY() < ArrayRight[indexRight].getY()) {
			nodes[indexVector] = ArrayLeft[indexLeft];
			indexLeft++;
		}
		if (Condition && ArrayLeft[indexLeft].getY() > ArrayRight[indexRight].getY()) {
			nodes[indexVector] = ArrayRight[indexRight];
			indexRight++;
		}
		if (!Condition && ArrayLeft[indexLeft].getX() < ArrayRight[indexRight].getX()) {
			nodes[indexVector] = ArrayLeft[indexLeft];
			indexLeft++;
		}
		if (!Condition && ArrayLeft[indexLeft].getX() > ArrayRight[indexRight].getX()) {
			nodes[indexVector] = ArrayRight[indexRight];
			indexRight++;
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
	delete[] ArrayLeft;
	delete[] ArrayRight;
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

Node::Node(point P)
{
	location = P;
	left = NULL;
	right = NULL;
}

void KDtree::findClosestNodes(Node* current, point target, int depth, int k, vector<DistanceNode>& result) {
	if (current == nullptr) {
		return;
	}

	int axis = depth % 2;
	Node* nextBranch = (axis == 0 && target.getX() < current->location.getX()) || (axis == 1 && target.getY() < current->location.getY()) ?
		current->left : current->right;
	Node * otherBranch = (axis == 0 && target.getX() < current->location.getX()) ||
		(axis == 1 && target.getY() < current->location.getY()) ?
		current->right : current->left;

	findClosestNodes(nextBranch, target, depth + 1, k, result);
	double distance = calculateDistance(current->location, target);

	result.push_back(DistanceNode(current, distance));
	sort(result.begin(), result.end());

	if (result.size() > static_cast<size_t>(k)) {
		result.pop_back();
	}

	if (abs(axis == 0 && target.getX() - current->location.getX() < result.back().distance)) {
		findClosestNodes(otherBranch, target, depth + 1, k, result);
	}
}

vector<Node*> KDtree::findClosestNodes1(const point& target, int k) {
	vector<DistanceNode> result;
	findClosestNodes(root, target, 0, k, result);
	vector<Node*> closestNodes;
	for (const auto& distanceNode : result) {
		closestNodes.push_back(distanceNode.node);
	}

	return closestNodes;
}