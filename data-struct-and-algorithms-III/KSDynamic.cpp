#include "KSDynamic.h"
#include <sstream>
/*
	Result table idea (for max capacity 4)
	
	weight:		| 0 | 1 | 2 | 3 | 4 | 
	val/weight	---------------------
				| 0 | 0 | 0 | 0 | 0 | <- guardian row to avoid index == -1 check
	5  /   4    | 0 |   |   |   |   |
	7  /   5    | 0 |   |   |   |   |
	1  /   1    | 0 |   |   |   | _ | <- sollution (best value)
*/
void KSDynamic::execute(KSItems * items, unsigned capacity) {
	delete result;
	result = new KSKnapsack();

	// create result table
	unsigned **resultTable = new unsigned*[capacity+1];
	for (size_t i = 0; i <= capacity; i++) {
		resultTable[i] = new unsigned[items->getSize() + 1];	// +1 for guardian row at the top of the table
	}

	// if the final weight was 0 - no items could be taken (weights are > 0)
	for (size_t i = 0; i <= items->getSize(); i++) {
		resultTable[0][i] = 0;
	}

	// guardian row
	for (size_t i = 1; i <= capacity; i++) {
		resultTable[i][0] = 0;
	}

	// calculations for each item 
	for (size_t item = 0; item < items->getSize(); item++) {
		unsigned itemValue = items->getItem(item).getValue();
		unsigned itemWeight = items->getItem(item).getWeight();

		// calculations for each (assumed) final weight
		for (size_t maxWeight = 1; maxWeight <= capacity; maxWeight++) {

			if (itemWeight > maxWeight) {
				// item cannot be included case (item+1 index because of guardian row)
				resultTable[maxWeight][item + 1] = resultTable[maxWeight][item];
			} else {
				// item can be included case - decision to make
				if (itemValue + resultTable[maxWeight - itemWeight][item] > resultTable[maxWeight][item]) {
					// should be included case
					resultTable[maxWeight][item + 1] = itemValue + resultTable[maxWeight - itemWeight][item];
				} else {
					resultTable[maxWeight][item + 1] = resultTable[maxWeight][item];
				}
			}
		}
	}

	// extract selected items
	int maxWeight = capacity, item = items->getSize();
	while (item > 0 && maxWeight >= 0) {
		// if optimal value wasn't taken from upper cell - the item was included
		if (resultTable[maxWeight][item] != resultTable[maxWeight][item - 1]) {
			// adding to front because we are checking items in reverse order 
			result->addItemFront(items->getItem(item-1));
			maxWeight -= items->getItem(item - 1).getWeight();
		} 

		item -= 1;
	}

	// dealocate result table
	for (size_t i = 0; i <= capacity; i++) {
		delete[] resultTable[i];
	}
	delete[] resultTable;
}

std::string KSDynamic::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Dynamic Programming Based" << std::endl << (result == nullptr ? "No result" : result->toString());

	return out.str();
}

