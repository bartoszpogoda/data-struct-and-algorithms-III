#include "KSFullSearch.h"

#include <sstream>
#include <iomanip>

void KSFullSearch::execute(KSItems * items, unsigned capacity) {
	delete result;
	result = new KSKnapsack();

	// fake algorithm
	for (size_t i = 0; i < items->getSize(); i++) {
		result->addItem(i, items->getWeight(i), items->getValue(i));
	}
}

std::string KSFullSearch::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Full Search" << std::endl << result->toString();

	return out.str();
}
