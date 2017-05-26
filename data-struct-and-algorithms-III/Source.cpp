#include "KSFullSearch.h"
#include "KSItems.h"

#include <iostream>

int main() {
	{
		KSFullSearch algorithm;

		unsigned capacity = 43;
		KSItems* items = new KSItems(5);
		items->addItem(5, 12);
		items->addItem(9, 23);
		items->addItem(15, 42);
		items->addItem(7, 13);
		items->addItem(2, 1);

		algorithm.execute(items, capacity);
		std::cout << algorithm.toString();

		delete items;
	}

	int x;
	std::cin >> x;
}