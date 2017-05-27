#include "KSGreedy.h"
#include "KSItemHeapSort.h"

#include <sstream>

void KSGreedy::execute(KSItems * items, unsigned capacity) {
	delete result;
	result = new KSKnapsack();

	// sort items based on itemDecision strategy
	KSItemHeapSort heapSort(itemDecision);
	KSItem* sortedItems = heapSort.sort(items->getItems(), items->getSize());

	unsigned remainingCapacity = capacity;
	for (size_t i = 0; i < items->getSize() && remainingCapacity > 0; i++) {
		if (sortedItems[i].getWeight() <= remainingCapacity) {
			result->addItemEnd(sortedItems[i]);
			remainingCapacity -= sortedItems[i].getWeight();
		}
	}

	delete[] sortedItems;
}

std::string KSGreedy::toString() {
	std::stringstream out;

	out << "Solution" << std::endl 
		<< "Greedy" << std::endl
		<< "Decision: " << itemDecision->toString() << std::endl
		<< (result == nullptr ? "No result" : result->toString());

	return out.str();
}
