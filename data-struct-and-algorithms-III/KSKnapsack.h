#pragma once
#include "List.h"
#include "KSItem.h"

#include <string>
#include <climits>

/*
	A structure to keep results for Knapsack problem
*/
class KSKnapsack {

	List<KSItem> *knapsackItems;

public:
	KSKnapsack() : knapsackItems(new List<KSItem>()) {}
	~KSKnapsack() { delete knapsackItems; }

	void addItemFront(KSItem item);
	void addItemEnd(KSItem item);

	std::string toString();
};