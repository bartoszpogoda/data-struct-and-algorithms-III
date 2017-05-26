#pragma once
#include "List.h"
#include <string>
#include <climits>

/*
	A structure to keep results for Knapsack problem
*/
class KSKnapsack {

	class KSKnapsackItem {
	public:
		unsigned id, weight, value;
		KSKnapsackItem() : id(UINT_MAX), weight(UINT_MAX), value(UINT_MAX) {}
		KSKnapsackItem(unsigned id, unsigned weight, unsigned value) : id(id), weight(weight), value(value) {}
	};

	List<KSKnapsackItem> *knapsackItems;

public:
	KSKnapsack() : knapsackItems(new List<KSKnapsackItem>()) {}	
	~KSKnapsack() { delete knapsackItems; }

	void addItemFront(unsigned id, unsigned weight, unsigned value);
	void addItemEnd(unsigned id, unsigned weight, unsigned value);
	// todo: item access

	std::string toString();
};