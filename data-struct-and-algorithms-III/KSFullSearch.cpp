#include "KSFullSearch.h"

#include <sstream>

KSFullSearch::RecursionStepResult KSFullSearch::recStep(KSItems * items, unsigned remainingCapacity, unsigned i) {
	if (i == -1) {
		return RecursionStepResult(0, 0);
	}

	unsigned ithItemWeight = items->getItem(i).getWeight();
	unsigned ithItemValue = items->getItem(i).getValue();

	if (remainingCapacity < ithItemWeight) {
		// cannot include i'th item case
		return recStep(items, remainingCapacity, i - 1);
	} else {
		// can include i'th item case - decision to make
		RecursionStepResult ithItemIncluded = recStep(items, remainingCapacity - ithItemWeight, i - 1);
		RecursionStepResult ithItemNotIncluded = recStep(items, remainingCapacity, i - 1);	

		if (ithItemValue + ithItemIncluded.value > ithItemNotIncluded.value) {
			return RecursionStepResult(ithItemIncluded.value + ithItemValue, ithItemIncluded.mask | (1 << i));
		} else {
			return ithItemNotIncluded;
		}
	}
}

void KSFullSearch::execute(KSItems * items, unsigned capacity) {
	delete result;
	result = new KSKnapsack();

	RecursionStepResult recursionResult = recStep(items, capacity, items->getSize() - 1);

	unsigned itemsToTakeMask = recursionResult.mask;
	unsigned currentMask = 1;

	for (size_t i = 0; i < items->getSize(); i++) {
		if(itemsToTakeMask & currentMask)
			result->addItemEnd(items->getItem(i));
		currentMask <<= 1;
	} 
}

std::string KSFullSearch::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Full Search" << std::endl << (result == nullptr ? "No result" : result->toString());

	return out.str();
}
