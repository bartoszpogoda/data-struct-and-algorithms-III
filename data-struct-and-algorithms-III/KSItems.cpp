#include "KSItems.h"

#include <sstream>
#include <iomanip>

std::string KSItems::toString() {
	std::stringstream out;
	int argWidth = 5;
	out << std::setfill(' ');

	out << std::setw(10) << std::left << "Items:" << std::setw(argWidth) << currentSize << std::endl << std::endl;

	out << std::right <<std::setw(argWidth) << "Item" << "  " 
		<< std::setw(argWidth) << "Size" << "  "
		<< std::setw(argWidth) << "Value" << std::endl;

	out << std::setfill('-') << std::setw(3*argWidth + 2*2) << "" << std::endl;

	out << std::setfill(' ');
	for (size_t i = 0; i < currentSize; i++) {
		out << std::setw(argWidth) << i << "  ";
		out << std::setw(argWidth) << weight[i] << "  ";
		out << std::setw(argWidth) << value[i] << "  " << std::endl;
	}

	return out.str();
}
