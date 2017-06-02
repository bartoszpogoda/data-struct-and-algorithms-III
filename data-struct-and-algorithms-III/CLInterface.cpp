#include "CLInterface.h"
#include <conio.h>

#include "KSFullSearch.h"
#include "KSDynamic.h"
#include "KSGreedy.h"

#include "TSFullSearch.h"
#include "TSGreedy.h"
#include "TSLocalSearch3Opt.h"

KSFileReader* CLInterface::ksFileReader = nullptr;
TSFileReader* CLInterface::tsFileReader = nullptr;
using namespace std;

void CLInterface::enter() {
	viewMainMenu();

	delete ksFileReader;
	delete tsFileReader;
}

int CLInterface::handleUserInput() {
	int c = 0;

	while ((c = getch())) {
		if (c == KEY_UP) {
			return -1;
		} else if (c == KEY_DOWN) {
			return 1;
		} else if (c == ENTER) {
			return 0;
		}
		c = 0;
	}
}

bool CLInterface::viewInputFilenameKS() {
	system("CLS");
	cout << " ++ KS, TS algorithms demo ++ " << endl << endl;

	cout << " > Enter filename: ";

	string readFilename;
	cin >> readFilename;

	delete ksFileReader;
	ksFileReader = new KSFileReader(readFilename);

	if (ksFileReader->success()) {
		cout << " > Read success";
		handleUserInput();
		return true;
	} else {
		cout << " > " << ksFileReader->getErrorMessage();
		delete ksFileReader;
		ksFileReader = nullptr;
		handleUserInput();
		return false;
	}
}

bool CLInterface::viewInputFilenameTS() {
	system("CLS");
	cout << " ++ KS, TS algorithms demo ++ " << endl << endl;

	cout << " > Enter filename: ";

	string readFilename;
	cin >> readFilename;

	delete tsFileReader;
	tsFileReader = new TSFileReader(readFilename);

	if (tsFileReader->success()) {
		cout << " > Read success";
		handleUserInput();
		return true;
	} else {
		cout << " > " << tsFileReader->getErrorMessage();
		delete tsFileReader;
		tsFileReader = nullptr;
		handleUserInput();
		return false;
	}
}

void CLInterface::viewMainMenu() {
	int selected = 0, max = 2, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta < 0)
				selected = max;
			else if (selected + selectedDelta > max)
				selected = 0;
			else
				selected += selectedDelta;

			system("CLS");
			cout << " ++ KS, TS algorithms demo ++ " << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Knapsack Problem" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Traveling Salesman Problem" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Exit" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			while (!viewInputFilenameKS());
			viewExecuteKS();

		} else if (selected == 1) {
			while (!viewInputFilenameTS());
			viewExecuteTS();
		}
	}
}

void CLInterface::viewExecuteKS() {
	system("CLS");

	KSFullSearch fullSearch;
	KSDynamic dynamic;
	KSGreedy greedy;

	unsigned capacity = ksFileReader->getCapacity();
	KSItems* items = ksFileReader->getItems();

	std::cout << "-- Knapsack Problem: " << std::endl;
	std::cout << "Capacity: " << capacity << std::endl;
	std::cout << items->toString() << std::endl;

	// full search 
	fullSearch.execute(items, capacity);
	std::cout << fullSearch.toString() << std::endl;

	// dynamic programming
	dynamic.execute(items, capacity);
	std::cout << dynamic.toString() << std::endl;

	// greedy
	greedy.setItemDecision(new KSGreedyDecisionValue());
	greedy.execute(items, capacity);
	std::cout << greedy.toString() << std::endl;

	greedy.setItemDecision(new KSGreedyDecisionValueToWeight());
	greedy.execute(items, capacity);
	std::cout << greedy.toString() << std::endl;

	delete items;

	cout << endl << "> Return to main menu";
	handleUserInput();
}

void CLInterface::viewExecuteTS() {
	system("CLS");

	TSFullSearch tsfs;
	TSGreedy tsgr;
	TSLocalSearch3Opt tsls;

	AdjacencyMatrix* cities = tsFileReader->getCities();

	std::cout << "-- TS Problem: " << std::endl;
	std::cout << "Number of cities: " << cities->getSize() << std::endl << std::endl;
	std::cout << cities->toString();

	tsfs.execute(cities);
	std::cout << tsfs.toString() << std::endl;

	tsgr.execute(cities);
	std::cout << tsgr.toString() << std::endl;

	TSPath* greedyResult = tsgr.getResult();

	tsls.setInitPath(greedyResult);
	tsls.execute(cities);
	std::cout << tsls.toString() << std::endl;

	tsls.setInitPath(nullptr);
	tsls.execute(cities);
	std::cout << tsls.toString() << std::endl;

	delete greedyResult;
	delete cities;

	handleUserInput();
}
