#include "KSKnapsack.h"

#include <sstream>
#include <iomanip>

void KSKnapsack::addItemFront(KSItem item) {
	knapsackItems->addFront(item);
}

void KSKnapsack::addItemEnd(KSItem item) {
	knapsackItems->addEnd(item);
}


std::string KSKnapsack::toString() {
	std::stringstream out;
	int argWidth = 5;

	unsigned totalWeight = 0, totalValue = 0;

	out << std::setfill('-') << std::setw(3 * argWidth + 2 * 2) << "" << std::endl;

	out << std::setfill(' ');
	out << std::right << std::setw(argWidth) << "Item" << "  "
		<< std::setw(argWidth) << "Size" << "  "
		<< std::setw(argWidth) << "Value" << std::endl;

	out << std::setfill('-') << std::setw(3 * argWidth + 2 * 2) << "" << std::endl;

	out << std::setfill(' ');
	for (size_t i = 0; i < knapsackItems->size(); i++) {
		out << knapsackItems->get(i).toString();

		totalWeight += knapsackItems->get(i).getWeight();
		totalValue += knapsackItems->get(i).getValue();
	}

	out << std::setfill('-') << std::setw(3 * argWidth + 2 * 2) << "" << std::endl;

	out << std::setfill(' ');
	out << std::right << std::setw(argWidth) << "Total" << "  "
		<< std::setw(argWidth) << totalWeight << "  "
		<< std::setw(argWidth) << totalValue << std::endl;

	return out.str();
}
