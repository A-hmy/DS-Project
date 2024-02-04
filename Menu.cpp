#include"Menu.h"
KDtree pizzeria;
HashMain mainPizzeria;
HashValley Valley;
int NumCommand;
ProgramState programstate;
void AddN(string NameOfValley) {
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mAdd neighborhood\033[0m\n";
	//string NameOfValley;
	point p[4];
	/*cout << "\t\t\t\033[38;5;202mName of the valley:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfValley);
	cout << "\033[0m";*/
	for (int i = 0; i < 4; i++) {
		cin >> p[i];
	}
	valley* newValley = new valley(NameOfValley, p);
	Valley.insert(newValley);
	cout << "\t\t\t\033[38;5;28mThe neighborhood was added:)\033[0m";
	NumCommand++;
	Command* command = new Command("Add-N", *newValley, NumCommand);
	programstate.insert(command);
	Sleep(3000);
}
void AddP(string NameOfPizzeria) {
	//string NameOfPizzeria;
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mAdd main branch\033[0m\n";
	//cout << "\t\t\t\033[38;5;202mName of the pizzeria:\033[0m";
	//cout << "\033[38;5;220m";
	//std::cin.ignore(1000, '\n');
	//getline(cin, NameOfPizzeria);
	//cout << "\033[0m";
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
		NumCommand++;
		Command* command = new Command("Add-P", *NewBranch, NumCommand);
		programstate.insert(command);
		Sleep(3000);
		mainPizzeria.insert(newMainBranch);
	}
}
void AddBr(string NameOfPizzeria) {
	//string NameOfPizzeria;
	string NameMainBranch;
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mAdd pizzeria\033[0m\n";
	/*cout << "\t\t\t\033[38;5;202mName of the pizzeria:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfPizzeria);
	cout << "\033[0m";*/
	cout << "\t\t\t\033[38;5;202mName of the main branch:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
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
			NumCommand++;
			Command* command = new Command("Add-Br", *NewBranch, NumCommand);
			programstate.insert(command);
			Sleep(3000);
		}
		else {
			cout << "\t\t\t\033[38;5;52mMain branch not found:(\033[0m";
			Sleep(3000);
		}
	}
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
			Branch deleted = pizzeria.searchBranch(x, y);
			MainBranchClass* Main = mainPizzeria.search(pizzeria.searchBranch(x, y).getNameMainBranch());
			Main->removeBranch(*deleteNode);
			Main->ReduceNumberOfBeranch();
			pizzeria.DeleteP(*deleteNode);
			cout << "\t\t\t\033[38;5;28mThe pizzeria was removed:)\033[0m";
			NumCommand++;
			Command* command = new Command("Del-Br", deleted, NumCommand);
			programstate.insert(command);
			Sleep(3000);
		}
	}
	else {
		cout << "\t\t\t\033[38;5;52mPizzeria not found:(\033[0m";
		Sleep(3000);
	}
}
void NearP() {
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay nearest pizzeria\033[0m\n";
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
		cout << "\t\t\t\033[38;5;52m";
		cout << "Points within radius " << z << " from the target point:\n";
		for (auto& point1 : pointsInRadius)
			cout << point1.getName() << "     :     " << point1.getCoordinate() << "\n";
		cout << "\033[0m";
	}
	else {
		cout << "\t\t\t\033[38;5;52mThere is no point:(\n\033[0m";
	}
	Sleep(1000);
}
void ListP(string NameOfValley) {
	//string NameOfValley;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay neighborhood pizzerias\033[0m\n";
	/*cout << "\t\t\t\033[38;5;202mName of the neighborhood:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfValley);
	cout << "\033[0m"*/;
	valley* v1 = Valley.search(NameOfValley);
	if (v1 == NULL) {
		cout << "\t\t\t\033[38;5;52mThere is no Valley:(\033[0m";
		Sleep(3000);
	}
	else {
		point* p1 = new point(v1->getPoint()[0].getX(), v1->getPoint()[0].getY());
		point* p2 = new point(v1->getPoint()[1].getX(), v1->getPoint()[1].getY());
		point* p3 = new point(v1->getPoint()[2].getX(), v1->getPoint()[2].getY());
		point* p4 = new point(v1->getPoint()[3].getX(), v1->getPoint()[3].getY());
		cout << "\t\t\t\033[38;5;28mPizzerias in " << NameOfValley << " neighborhood:";
		pizzeria.FindPointsInRectangle(*p1, *p2, *p3, *p4);
		cout << "\033[0m";
		Sleep(3000);
	}
}
void Help() {
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\033[38;5;202m      PIZZA HOUSE\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAdd-N\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mAdd valley\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAdd-P\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mAdd main branch\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAdd-Br\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mAdd pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mDel-Br\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mRemove pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mList-P\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay of pizzerias in a neighborhood\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mList-Brs\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay pizzerias of a main branch\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mNear-P\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay nearest pizzeria\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mNear-Br\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay the nearest pizzeria of a branch\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mAvail-P\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay available pizzerias\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mMost-Brs\033[0m""\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mDisplay the pizzeria with the most branches\033[0m\n";
	cout << "\t\t\t\033[38;5;202m*" << "\033[38;5;30mUndo\033[0m""\t\t\033[38;5;202m------>\033[0m\t\t""\033[38;5;30mReturn to previous commands\033[0m\n";
	cout << "\t\t\t\033[38;5;202mInput format:COMMAND_NAME [NAME] && COMMAND_NAME [NAME]\033[0m\n";
	cout << "\t\t\t\033[38;5;202mEnter:\033[0m";
}
void ListBrs(string NameOfPizzeria) {
	//string NameOfPizzeria;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay of one-branch pizzerias\033[0m\n";
	/*cout << "\t\t\t\033[38;5;202mName of the pizzeria:\033[0m";
	cout << "\033[38;5;220m";
	std::cin.ignore(1000, '\n');
	getline(cin, NameOfPizzeria);
	cout << "\033[0m";*/
	MainBranchClass* Main = mainPizzeria.search(NameOfPizzeria);
	Main->printBranch();
	Sleep(3000);
}
void NearBr(string NameMainBranch)//=============
{
	//string NameMainBranch;
	float x, y;
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mDisplay the nearest pizzeria of a branch\033[0m\n";
	//cout << "\t\t\t\033[38;5;202mName of the main branch:\033[0m";
	//cout << "\033[38;5;220m";
	//std::cin.ignore(1000, '\n');
	//getline(cin, NameMainBranch);
	//cout << "\033[0m";
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
void Undo() {
	cout << "\n\n\n\n";
	cout << "\t\t\t\033[38;5;30mUndo\033[0m\n";
	int p;
	cout << "\t\t\t\033[38;5;202mP:\033[0m";
	cout << "\033[38;5;220m";
	cin >> p;
	cout << "\033[0m";
	if (p < NumCommand) {
		for (int i = NumCommand; i > p; i--, NumCommand--) {
			Command* UndoCom = programstate.search(i);
			if (UndoCom->getName() == "Add-P") {
				MainBranchClass* newMainBranch = new MainBranchClass(UndoCom->getExecuteNode().getName(), UndoCom->getExecuteNode().getCoordinate().getX(), UndoCom->getExecuteNode().getCoordinate().getY());
				pizzeria.DeleteP(UndoCom->getExecuteNode().getCoordinate());
				mainPizzeria.Deleted(*newMainBranch);
				programstate.Deleted(*UndoCom);
				cout << "\t\t\t\033[38;5;88m";
				cout << "Pizzeria" << UndoCom->getExecuteNode().getName() << "was removed:)\n";
				cout << "\033[0m";
			}
			else if (UndoCom->getName() == "Add-Br") {
				MainBranchClass* Main = mainPizzeria.search(pizzeria.searchBranch(UndoCom->getExecuteNode().getCoordinate().getX(), UndoCom->getExecuteNode().getCoordinate().getY()).getNameMainBranch());
				Main->removeBranch(UndoCom->getExecuteNode().getCoordinate());
				Main->ReduceNumberOfBeranch();
				pizzeria.DeleteP(UndoCom->getExecuteNode().getCoordinate());
				programstate.Deleted(*UndoCom);
				cout << "\t\t\t\033[38;5;88m";
				cout << "Pizzeria " << UndoCom->getExecuteNode().getName() << " was removed:)\n";
				cout << "\033[0m";
			}
			else if (UndoCom->getName() == "Del-Br")
			{
				pizzeria.insert(UndoCom->getExecuteNode());
				MainBranchClass* Main = mainPizzeria.search(UndoCom->getExecuteNode().getNameMainBranch());
				Main->setBranch(UndoCom->getExecuteNode());
				Main->AddNumberOfBranch();
				programstate.Deleted(*UndoCom);
				cout << "\t\t\t\033[38;5;28m";
				cout << "Pizzeria " << UndoCom->getExecuteNode().getName() << " was added:)\n";
				cout << "\033[0m";
			}
			else if (UndoCom->getName() == "Add-N") {
				Valley.Deleted(UndoCom->getExecuteValley());
				programstate.Deleted(*UndoCom);
				cout << "\t\t\t\033[38;5;88m";
				cout << "Pizzeria " << UndoCom->getExecuteValley().getName() << " was removed:)\n";
				cout << "\033[0m";
			}
		}
	}
	while (1) {
		cout << "\t\t\t\033[38;5;202m";
		cout << "Press 1 to continue";
		cout << "\033[0m";
		string en;
		cout << "\033[38;5;220m";
		std::cin.ignore(1000, '\n');
		getline(cin, en);
		cout << "\033[0m";
		if (en == "1")
			break;
	}
}
bool Vallid(const string& rule) {
	stringstream str(rule);
	string act;
	str >> act;
	if (act == "Add-N" || act == "Add-P" || act == "Add-Br" || act == "Del-Br" || act == "List-P" || act == "List-Brs" || act == "Near-P" || act == "Near-Br" || act == "Avail-P" || act == "Most-Brs" || act == "Undo") {
		return true;
	}

	return false;
}
vector<string> sentence(const string& input) {
	stringstream strinput(input);
	string rule;
	vector<string> sentence;
	while (getline(strinput, rule, '&')) {
		if (rule != "")
			sentence.push_back(rule);
	}
	return sentence;
}
void Menu() {
	string enter;
	vector<string> input;
	while (1) {
		system("cls");
		while (1) {
			Help();
			cout << "\033[38;5;220m";
			//std::cin.ignore(1000, '\n');
			getline(cin, enter);
			cout << "\033[0m";
			input = sentence(enter);
			bool flag = true;
			for (const auto& str : input) {
				if (!Vallid(str)) {
					//cout << "Invalid Format: " << str << endl;
					flag = false;
					break;
				}
			}
			if (flag) {
				system("cls");
				break;
			}
			/*if (enter == "Add-N" || enter == "Add-P" || enter == "Add-Br" || enter == "Del-Br" || enter == "List-P" || enter == "List-Brs" || enter == "Near-Br" || enter == "Near-P" || enter == "Avail-P" || enter == "Most-Brs" || enter == "Undo") {
				system("cls");
				break;
			}*/
			system("cls");
		}
		for (const auto& rule1 : input) {
			stringstream rulestr(rule1);
			string act, str1;
			rulestr >> act >> str1;
			size_t start_pos = str1.find("[");
			size_t end_pos = str1.find("]");
			string name;
			if (start_pos != string::npos && end_pos != string::npos)
				name = str1.substr(start_pos + 1, end_pos - start_pos - 1);
			if (act == "Add-N") { AddN(name); }
			if (act == "Add-P") { AddP(name); }
			if (act == "Add-Br") { AddBr(name); }
			if (act == "Del-Br") { DelBr(); }
			if (act == "List-P") { ListP(name); NumCommand++; }
			if (act == "List-Brs") { ListBrs(name); NumCommand++; }
			if (act == "Near-P") { NearP(); NumCommand++; }
			if (act == "Near-Br") { NearBr(name); NumCommand++; }
			if (act == "Avail-P") { AvailP(); NumCommand++; }
			if (act == "Most-Brs") { MostBrs(); NumCommand++; }
			if (act == "Undo") { Undo(); }
			if (act != "Add-N" && act != "Add-P" && act != "Add-Br" && act != "Del-Br") {
				Branch* temp = new Branch();
				Command* command = new Command("***", *temp, NumCommand);
			}
		}
	}
}

