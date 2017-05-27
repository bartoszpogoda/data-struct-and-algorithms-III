#pragma once
#include "KSItem.h"

#include <string>
/*
	A structure to keep input items for Knapsack problem
	It's not safe, indexes must be validated outside
*/
class KSItems {
	KSItem * items;
	unsigned size, currentSize;

public:
	KSItems(int size) : currentSize(0), size(size), items(new KSItem[size]) {}
	~KSItems() { delete[] items;  }

	void addItem(unsigned weight, unsigned value) { items[currentSize] = KSItem(currentSize, weight, value); currentSize++; }

	unsigned getSize() { return size; }
	KSItem getItem(int id) { return items[id]; }

	std::string toString();
};