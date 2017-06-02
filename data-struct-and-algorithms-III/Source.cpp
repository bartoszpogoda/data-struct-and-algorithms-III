#include "KSFullSearch.h"
#include "KSDynamic.h"
#include "KSItems.h"
#include "KSGreedy.h"

#include "TSFullSearch.h"
#include "TSGreedy.h"
#include "TSLocalSearch3Opt.h"

#include "KSFileReader.h"
#include "TSFileReader.h"

#include "CLInterface.h"

#include <iostream>
#include <ctime>

int main() {

	CLInterface::enter();

	/*KSFileReader reader("ksinput.txt");
	std::cout << reader.getItems()->toString() << " CAP: " << reader.getCapacity();

	TSFileReader tsReader("tsinput.txt");
	std::cout << std::endl << tsReader.getCities()->toString();


	{
		// KS PROBLEM DEMO

		KSFullSearch fullSearch;
		KSDynamic dynamic;
		KSGreedy greedy;

		unsigned capacity = 60;
		KSItems* items = new KSItems(7);
		items->addItem(10, 60);
		items->addItem(15, 11);
		items->addItem(14, 142);
		items->addItem(17, 32);
		items->addItem(13, 12);
		items->addItem(14, 34);
		items->addItem(30, 44);

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
	}

	{
		// TS PROBLEM DEMO

		TSFullSearch tsfs;
		TSGreedy tsgr;
		TSLocalSearch3Opt tsls;

		srand(time(nullptr));
		int n = 9;
		AdjacencyMatrix* cities = new AdjacencyMatrix(n);
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				if (i != j) cities->addEdge(i, j, rand() % 100);
			}
		}

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
	}
	*/
	int x;
	std::cin >> x;
}