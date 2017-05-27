#include "KSItem.h"

#include <sstream>
#include <iomanip>

std::string KSItem::toString() {
	std::stringstream out;
	int argWidth = 5;

	out << std::setfill(' ');
		out << std::setw(argWidth) << id << "  ";
		out << std::setw(argWidth) << weight << "  ";
		out << std::setw(argWidth) << value << "  " << std::endl;

	return out.str();
}
