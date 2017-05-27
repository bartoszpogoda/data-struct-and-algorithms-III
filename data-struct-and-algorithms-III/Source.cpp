#include "KSFullSearch.h"
#include "KSDynamic.h"
#include "KSItems.h"
#include "KSGreedy.h"

#include <iostream>

int main() {
	{
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

	int x;
	std::cin >> x;
}