#include "KSFullSearch.h"
#include "KSItems.h"

#include <iostream>

int main() {
	{
		KSFullSearch algorithm;

		unsigned capacity = 50;
		KSItems* items = new KSItems(3);
		items->addItem(10, 60);
		items->addItem(20, 100);
		items->addItem(30, 120);
		std::cout << "Capacity: " << capacity << std::endl;
		std::cout << items->toString() << std::endl;

		algorithm.execute(items, capacity);
		std::cout << algorithm.toString();

		delete items;
	}

	int x;
	std::cin >> x;
}