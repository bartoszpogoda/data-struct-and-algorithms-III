#pragma once

#include <string>
/*
	A structure to keep input item for Knapsack problem
*/
class KSItem {
	unsigned id, weight, value;

public:
	KSItem() : id(UINT_MAX), weight(UINT_MAX), value(UINT_MAX) { }
	KSItem(unsigned id, unsigned weight, unsigned value) : id(id), weight(weight), value(value) {}

	unsigned getId() { return id; }
	unsigned getWeight() { return weight; }
	unsigned getValue() { return value; }

	std::string toString();
};