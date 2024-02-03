#include"Menu.h"
KDtree pizzeria;
HashMain mainPizzeria;
HashValley Valley;
void AddP() {
	string NameOfPizzeria;
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mAdd main branch\033[0m\n";
	cout << "\t\t\t\033[38;5;202mName of the pizzeria:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfPizzeria);
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mX:\033[0m";
	cout << "\033[38;5;220m";
	cin >> x;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mY:\033[0m";
	cout << "\033[38;5;220m";
	cin >> y;
	cout << "\033[0m";
	Branch* NewBranch = new Branch(NameOfPizzeria, x, y, "", 1);
	MainBranchClass* newMainBranch = new MainBranchClass(NameOfPizzeria, x, y);
	if (pizzeria.search(x, y)) {
		cout << "\t\t\t\033[38;5;52mThere is another pizzeria in this place:(\033[0m";
		Sleep(3000);
	}
	else {
		pizzeria.insert(*NewBranch);
		cout << "\t\t\t\033[38;5;28mPizzeria added:)\033[0m";
		Sleep(3000);
		mainPizzeria.insert(newMainBranch);
	}
}
void AddBr() {
	string NameOfPizzeria;
	string NameMainBranch;
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mAdd pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202mName of the pizzeria:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfPizzeria);
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mName of the main branch:\033[0m";
	cout << "\033[38;5;220m";
	getline(cin, NameMainBranch);
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mX:\033[0m";
	cout << "\033[38;5;220m";
	cin >> x;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mY:\033[0m";
	cout << "\033[38;5;220m";
	cin >> y;
	cout << "\033[0m";
	Branch* NewBranch = new Branch(NameOfPizzeria, x, y, NameMainBranch, 0);
	if (pizzeria.search(x, y)) {
		cout << "\t\t\t\033[38;5;52mThere is another pizzeria in this place:(\033[0m";
		Sleep(3000);
	}
	else {
		MainBranchClass* Main = mainPizzeria.search(NameMainBranch);
		if (Main != nullptr) {
			pizzeria.insert(*NewBranch);
			Main->setBranch(*NewBranch);
			Main->AddNumberOfBranch();
			cout << "\t\t\t\033[38;5;28mPizzeria added:)\033[0m";
			Sleep(3000);
		}
		else {
			cout << "\t\t\t\033[38;5;52mMain branch not found:(\033[0m";
			Sleep(3000);
		}
	}
}
void NearP() {
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay nearest pizzeria\033[0m\n";
	//cout << "\t\t\t\033[38;5;202mEnter the coordinates of the Point.(X,Y)\033[0m\n";
	cout << "\t\t\t\033[38;5;202mX:\033[0m";
	cout << "\033[38;5;220m";
	cin >> x;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mY:\033[0m";
	cout << "\033[38;5;220m";
	cin >> y;
	cout << "\033[0m";
	point* p1 = new point(x, y);
	Node* closestNode = pizzeria.FindClosest1(*p1);
	if (closestNode != nullptr) {

		cout << "Closest node to the target point:    " << closestNode->pizzeria.getName() << "      :      " << "(" << closestNode->pizzeria.getCoordinate().getX() << ", " << closestNode->pizzeria.getCoordinate().getY() << ")\n";

		cout << "\t\t\t\033[38;5;28mClosest node to the target point:" << closestNode->pizzeria.getName() << ""
			<< closestNode->pizzeria.getCoordinate();
		cout << "\033[0m";
		Sleep(3000);

	}
	else {
		cout << "\t\t\t\033[38;5;52mNo points in the KD Tree:(\033[0m";
		Sleep(3000);
	}

}
void AvailP() {
	float x, y, z;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay available pizzerias\033[0m\n";
	cout << "\t\t\t\033[38;5;202mX:\033[0m";
	cout << "\033[38;5;220m";
	cin >> x;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mY:\033[0m";
	cout << "\033[38;5;220m";
	cin >> y;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mEnter the radius:\033[0m\n";
	cout << "\t\t\t\033[38;5;202mR:\033[0m";
	cout << "\033[38;5;220m";
	cin >> z;
	cout << "\033[0m";
	point* p1 = new point(x, y);

	vector<Branch> pointsInRadius = pizzeria.FindPointsInCircle1(*p1, z);
	if (!pointsInRadius.empty()) {
		cout << "Points within radius " << z << " from the target point:\n";
		for (auto& point1 : pointsInRadius)
			cout << point1.getName() << "     :     " << point1.getCoordinate() << "\n";
	}
	else {
		cout << "There is no point.\n\n";
	}
}
void ListP() {
	string NameOfValley;
	cout << "\033[1;31mEnter the name of the Valley:\033[0m\n";
	cout << "\033[1;32m";
	cin >> NameOfValley;
	valley *v1=Valley.search(NameOfValley);
	if (v1 == NULL) {
		cout << "There is no Valley.\n\n";
	}
	else {
		point* p1 = new point(v1->getPoint()[0].getX(), v1->getPoint()[0].getY());
		point* p2 = new point(v1->getPoint()[1].getX(), v1->getPoint()[1].getY());
		point* p3 = new point(v1->getPoint()[2].getX(), v1->getPoint()[2].getY());
		point* p4 = new point(v1->getPoint()[3].getX(), v1->getPoint()[3].getY());
		pizzeria.FindPointsInRectangle(*p1, *p2, *p3, *p4);
	}


	vector<Branch> pointsWithinRadius = pizzeria.FindPointsInCircle1(*p1, z);
	cout << "\t\t\t\033[38;5;28mPoints within radius " << z << " from the target point:\n";
	for (auto& point1 : pointsWithinRadius)
		cout << point1.getCoordinate() << "\n";
	cout << "\033[0m";
	Sleep(3000);

}
void Help() {
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\033[38;5;202m      PIZZA HOUSE\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAdd-N\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mAdd valley\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAdd-P\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mAdd main branch\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAdd-Br\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mAdd pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mDel-Br\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mRemove pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mList-P\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay of pizzerias in a neighborhood\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mList-Brs\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay of one-branch pizzerias\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mNear-P\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay nearest pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mNear-Br\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay the nearest pizzeria of a branch\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAvail-P\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay available pizzerias\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mMost-Brs\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay the pizzeria with the most branches\033[0m\n";
	cout << "\t\t\t\033[38;5;202mEnter:\033[0m";
}
void DelBr() {
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mRemove a pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202mX:\033[0m";
	cout << "\033[38;5;220m";
	cin >> x;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mY:\033[0m";
	cout << "\033[38;5;220m";
	cin >> y;
	cout << "\033[0m";
	point* deleteNode = new point(x, y);
	if (pizzeria.search(x, y)) {
		if (pizzeria.searchBranch(x, y).getMainFlag()) {
			cout << "\t\t\t\033[38;5;52mThe main branch cannot be deleted:(\033[0m";
			Sleep(3000);
		}
		else {
			MainBranchClass* Main = mainPizzeria.search(pizzeria.searchBranch(x, y).getNameMainBranch());
			Main->removeBranch(*deleteNode);
			Main->ReduceNumberOfBeranch();
			pizzeria.DeleteP(*deleteNode);
			cout << "\t\t\t\033[38;5;28mThe pizzeria was removed:)\033[0m";
			Sleep(3000);
		}
	}
	else {
		cout << "\t\t\t\033[38;5;52mPizzeria not found:(\033[0m";
		Sleep(3000);
	}
}
void ListBrs() {
	string NameOfPizzeria;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay of one-branch pizzerias\033[0m\n";
	cout << "\t\t\t\033[38;5;202mName of the pizzeria:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfPizzeria);
	cout << "\033[0m";
	MainBranchClass* Main = mainPizzeria.search(NameOfPizzeria);
	Main->printBranch();
	Sleep(3000);
}
void AddN() {
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mAdd neighborhood\033[0m\n";
	string NameOfValley;
	point p[4];

	cout << "\033[1;31mEnter the name of the Valley:\033[0m\n";
	cout << "\033[1;32m";
	cin >> NameOfValley;

	cout << "\t\t\t\033[38;5;202mName of the valley:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfValley);
	cout << "\033[0m";

	for (int i = 0; i < 4; i++) {
		cin >> p[i];
	}
	valley* newValley = new valley(NameOfValley, p);
	Valley.insert(newValley);
	cout << "\t\t\t\033[38;5;28mThe neighborhood was added:)\033[0m";
	Sleep(3000);
}
void NearBr()//=============
{
	string NameMainBranch;
	float x, y;
	cout << "\t\t\t\033[38;5;202mName of the main branch:\033[0m";
	cout << "\033[38;5;220m";
	getline(cin, NameMainBranch);
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mX:\033[0m";
	cout << "\033[38;5;220m";
	cin >> x;
	cout << "\033[0m";
	cout << "\t\t\t\033[38;5;202mY:\033[0m";
	cout << "\033[38;5;220m";
	cin >> y;
	cout << "\033[0m";
	point* p1 = new point(x, y);
	MainBranchClass* Main = mainPizzeria.search(NameMainBranch);
	if (Main != NULL) {
		KDtree pizzeriaBranches;
		pizzeriaBranches.setNodes(Main->getBranches());
		pizzeriaBranches.buildtree();
		Node* closestNode = pizzeriaBranches.FindClosest1(*p1);
		if (closestNode != nullptr) {
			cout << "\t\t\t\033[38;5;28mClosest node to the target point:" << closestNode->pizzeria.getName() << ""
				<< closestNode->pizzeria.getCoordinate();
			cout << "\033[0m";
			Sleep(3000);
		}
		else {
			cout << "\t\t\t\033[38;5;52mNo points in the KD Tree:(\033[0m\n";
			Sleep(3000);
		}
	}
	else {
		cout << "\t\t\t\033[38;5;52mMain branch not found:(\033[0m\n";
		Sleep(3000);
	}

}
void MostBrs()
{
	MainBranchClass most = mainPizzeria.mostBranches();
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;28mThe pizzeria with the most branches:\033[0m";
	cout << "\033[38;5;28m";
	cout << most.getName() << "With " << most.getNumberOfBranch() << " branches";
	cout << "\033[0m";
	Sleep(3000);
}
void Menu() {
	string enter;
	while (1) {
		system("cls");
		while (1) {
			Help();
			cout << "\033[38;5;220m";
			cin >> enter;
			cout << "\033[0m";
			if (enter == "Add-N" || enter == "Add-P" || enter == "Add-Br" || enter == "Del-Br" || enter == "List-P" || enter == "List-Brs" || enter == "Near-Br" || enter == "Near-P" || enter == "Avail-P" || enter == "Most-Brs") {
				system("cls");
				break;
			}
			system("cls");
		}
		if (enter == "Add-N") { AddN(); }//1*****
		if (enter == "Add-P") { AddP(); }//2******
		if (enter == "Add-Br") { AddBr(); }//3******
		if (enter == "Del-Br") { DelBr(); }//4*******
		if (enter == "List-P") { ListP(); }//5********
		if (enter == "List-Brs") { ListBrs(); }//6********
		if (enter == "Near-P") { NearP(); }//7******
		if (enter == "Near-Br") { NearBr(); }//8
		if (enter == "Avail-P") { AvailP(); }//9******
		if (enter == "Most-Brs") { MostBrs(); }//10
	}
}

