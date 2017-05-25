#pragma once

#include <string>
/*
	A structure to keep input items for Knapsack problem
	It's not safe, indexes must be validated outside
*/
class KSItems {
	unsigned size, *weight, *value;
	unsigned currentSize;

public:
	KSItems(int size) : currentSize(0), size(size), weight(new unsigned[size]), value(new unsigned[size]) {}
	KSItems() { delete[] weight; delete[] value; }

	void addItem(unsigned weight, unsigned value) { this->weight[currentSize] = weight; this->value[currentSize++] = value; }

	unsigned getSize() { return size; }
	unsigned getWeight(int i) { return weight[i]; }
	unsigned getValue(int i) { return value[i]; }

	std::string toString();
};