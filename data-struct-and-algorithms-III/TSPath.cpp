#include "TSPath.h"

#include <iomanip>
#include <sstream>


void TSPath::add(unsigned pathNode) {
	if (currentSize != size)
		path[currentSize] = pathNode;

	currentSize++;
}

std::string TSPath::toString() {
	std::stringstream out;
	int argWidth = 2;

	out << std::left << std::setw(7) << "Length" << "= " << length << std::endl;
	out << std::left << std::setw(7) << "Path" << "= ";
	out << std::setfill(' ');
	for (size_t i = 0; i < currentSize; i++) {
		out << std::setw(argWidth) << path[i] << (i != currentSize - 1 ? " - " : " ");
	}

	out << std::endl;

	return out.str();
}
