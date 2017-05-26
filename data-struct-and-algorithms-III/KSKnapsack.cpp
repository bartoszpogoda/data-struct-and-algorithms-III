#include "KSKnapsack.h"

#include <sstream>
#include <iomanip>

void KSKnapsack::addItemFront(unsigned id, unsigned weight, unsigned value) {
	knapsackItems->addFront(KSKnapsackItem(id, weight, value));
}

void KSKnapsack::addItemEnd(unsigned id, unsigned weight, unsigned value) {
	knapsackItems->addEnd(KSKnapsackItem(id, weight, value));
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
		out << std::setw(argWidth) << knapsackItems->get(i).id << "  ";
		out << std::setw(argWidth) << knapsackItems->get(i).weight << "  ";
		out << std::setw(argWidth) << knapsackItems->get(i).value << "  " << std::endl;

		totalWeight += knapsackItems->get(i).weight;
		totalValue += knapsackItems->get(i).value;
	}

	out << std::setfill('-') << std::setw(3 * argWidth + 2 * 2) << "" << std::endl;

	out << std::setfill(' ');
	out << std::right << std::setw(argWidth) << "Total" << "  "
		<< std::setw(argWidth) << totalWeight << "  "
		<< std::setw(argWidth) << totalValue << std::endl;

	return out.str();
}
