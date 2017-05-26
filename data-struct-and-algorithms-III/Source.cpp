#include "KSFullSearch.h"
#include "KSDynamic.h"
#include "KSItems.h"

#include <iostream>

int main() {
	{
		KSFullSearch algorithm;

		unsigned capacity = 60;
		KSItems* items = new KSItems(7);
		items->addItem(10, 60);
		items->addItem(15, 22);
		items->addItem(14, 22);
		items->addItem(17, 32);
		items->addItem(13, 12);
		items->addItem(14, 23);
		items->addItem(30, 44);

		std::cout << "Capacity: " << capacity << std::endl;
		std::cout << items->toString() << std::endl;

		algorithm.execute(items, capacity);
		std::cout << algorithm.toString();

		KSDynamic algorithmDynamic;
		algorithmDynamic.execute(items, capacity);
		std::cout << algorithmDynamic.toString();

		delete items;
	}

	int x;
	std::cin >> x;
}