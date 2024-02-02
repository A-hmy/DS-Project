#include"Menu.h"
KDtree pizzeria;
HashMain mainPizzeria;
HashValley Valley;
void AddP() {
	string NameOfPizzeria;
	float x, y;
	cout << "\033[1;31mEnter the name of the pizzeria:\033[0m\n";
	cout << "\033[1;32m";
	cin >> NameOfPizzeria;
	cout << "\033[1;31mEnter the coordinates of the pizzeria.(X,Y)\033[0m\n";
	cout << "\033[1;31mX:\033[0m";
	cin >> x;
	cout << "\033[1;31mY:\033[0m";
	cin >> y;
	Branch* NewBranch = new Branch(NameOfPizzeria, x, y, "", 1);
	MainBranchClass* newMainBranch = new MainBranchClass(NameOfPizzeria, x, y);
	if (pizzeria.search(x, y)) {
		cout << "error";
	}
	else {
		pizzeria.insert(*NewBranch);
		cout << "\033[1;31mPizzeria added:):\033[0m\n";
		mainPizzeria.insert(newMainBranch);
	}
}
void AddBr() {
	string NameOfPizzeria;
	string NameMainBranch;
	float x, y;
	cout << "\033[1;31mEnter the name of the pizzeria:\033[0m\n";
	cout << "\033[1;32m";
	//getline(cin, NameOfPizzeria);
	//cin.ignore(100, '\n'); // Ignore the next 100 characters or until newline is encountered
	cin >> NameOfPizzeria;
	cout << "\033[1;31mEnter the name of the main branch:\033[0m\n";
	cout << "\033[1;32m";
	cin >> NameMainBranch;
	cout << "\033[1;31mEnter the coordinates of the pizzeria.(X,Y)\033[0m\n";
	cout << "\033[1;31mX:\033[0m";
	cin >> x;
	cout << "\033[1;31mY:\033[0m";
	cin >> y;
	Branch* NewBranch = new Branch(NameOfPizzeria, x, y, NameMainBranch, 0);
	if (pizzeria.search(x, y)) {
		cout << "error";
	}
	else {
		MainBranchClass* Main = mainPizzeria.search(NameMainBranch);
		if (Main != nullptr) {
			pizzeria.insert(*NewBranch);
			Main->setBranch(*NewBranch);
			Main->AddNumberOfBranch();
			cout << "\033[1;31mPizzeria added:):\033[0m\n";
		}
		else {
			cout << "Main not found";
		}
	}
}
void NearP() {
	float x, y;
	cout << "\033[1;31mEnter the coordinates of the Point.(X,Y)\033[0m\n";
	cout << "\033[1;31mX:\033[0m";
	cin >> x;
	cout << "\033[1;31mY:\033[0m";
	cin >> y;
	point* p1 = new point(x, y);
	Node* closestNode = pizzeria.FindClosest1(*p1);


	if (closestNode != nullptr) {
		cout << "Closest node to the target point: (" << closestNode->pizzeria.getCoordinate().getX() << ", " << closestNode->pizzeria.getCoordinate().getY() << ")\n";
	}
	else {
		cout << "No points in the KD Tree.\n";
	}
	// Hear we have to print the specifications

}
void AvailP() {
	float x, y, z;
	cout << "\033[1;31mEnter the coordinates of the Point.(X,Y)\033[0m\n";
	cout << "\033[1;31mX:\033[0m";
	cin >> x;
	cout << "\033[1;31mY:\033[0m";
	cin >> y;
	cout << "\033[1;31mEnter the radius\033[0m\n";
	cout << "\033[1;31mX:\033[0m";
	cin >> z;
	point* p1 = new point(x, y);
	vector<Branch> pointsWithinRadius = pizzeria.FindPointsInCircle1(*p1, z);

	cout << "Points within radius " << z << " from the target point:\n";
	for (auto& point1 : pointsWithinRadius)
		cout << point1.getCoordinate() << "\n";
}
void Help() {
	cout << "\033[1;32mW";
	cout << "\033[1;31me";
	cout << "\033[1;37ml";
	cout << "\033[1;34mc";
	cout << "\033[1;33mo";
	cout << "\033[1;36mm";
	cout << "\033[1;35me\033[0m\n";
	cout << "\033[1;31mWhat do you want to do?\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Add-N if you want to add neighborhood.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Add-P if you want to add a main branch of the pizzeria. \033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Add-Br if you want to add a pizzeria.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Del-Br if you want to remove the pizzeria.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter List-P if you want to get a list of pizzerias in a neighborhood.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter List-Brs if you want to get the list of pizzeria branches of a main branch.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Near-P if you want to find the nearest pizzeria.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Avail-P if you want to find available pizzerias.\033[0m\n";
	cout << "\033[1;31m*" << "\033[1;34mEnter Most-Brs if you want to get the name of the pizzeria with the most number of branches.\033[0m\n";
	cout << "\033[1;32mEnter:\033[0m\n";
}
void DelBr() {
	float x, y;
	cout << "\033[1;31mEnter the coordinates of the pizzeria you want to delete:\033[0m\n";
	cout << "\033[1;31mX:\033[0m";
	cin >> x;
	cout << "\033[1;31mY:\033[0m";
	cin >> y;
	point* deleteNode = new point(x, y);
	if (pizzeria.search(x, y)) {
		if (pizzeria.searchBranch(x, y).getMainFlag())
			cout << "error";// if it is main
		else {
			MainBranchClass* Main = mainPizzeria.search(pizzeria.searchBranch(x, y).getNameMainBranch());
			Main->removeBranch(*deleteNode);
			Main->ReduceNumberOfPencils();
			pizzeria.DeleteP(*deleteNode);
		}
	}
	else
		cout << "error";//not exist
}
void ListBrs() {
	string NameOfPizzeria;
	cout << "\033[1;31mEnter the name of the pizzeria:\033[0m\n";
	cout << "\033[1;32m";
	cin >> NameOfPizzeria;
	MainBranchClass* Main = mainPizzeria.search(NameOfPizzeria);
	Main->printBranch();
}
void AddN() {
	string NameOfValley;
	point p[4];
	cout << "\033[1;31mEnter the name of the pizzeria:\033[0m\n";
	cout << "\033[1;32m";
	cin >> NameOfValley;
	for (int i = 0; i < 4; i++) {
		cout << "enter x and y";
		cin >> p[i];
	}
	valley* newValley = new valley(NameOfValley, p);
	Valley.insert(newValley);
}
void Menu() {
	string enter;
	while (1) {
		while (1) {
			Help();
			cin >> enter;
			if (enter == "Add-N" || enter == "Add-P" || enter == "Add-Br" || enter == "Del-Br" || enter == "List-P" || enter == "List-Brs" || enter == "Near-Br" || enter == "Near-P" || enter == "Avail-P" || enter == "Most-Brs") {
				break;
			}
			system("cls");
		}
		if (enter == "Add-N") { AddN(); }//1*****
		if (enter == "Add-P") { AddP(); }//2******
		if (enter == "Add-Br") { AddBr(); }//3******
		if (enter == "Del-Br") { DelBr(); }//4*******
		if (enter == "List-P") {}//5
		if (enter == "List-Brs") { ListBrs(); }//6********
		if (enter == "Near-P") { NearP(); }//7******
		if (enter == "Near-Br") {}//8
		if (enter == "Avail-P") { AvailP(); }//9******
		if (enter == "Most-Brs") {}//10
	}
}
