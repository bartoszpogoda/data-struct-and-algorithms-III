#include "KSFileReader.h"
#include <fstream>

void KSFileReader::read(std::string filename) {
	std::ifstream file = std::ifstream(filename);
	errorFlag = false;
	unsigned numberOfItems = 0;

	if (items != nullptr) {
		return;
	}

	if (file.is_open()) {

		file >> capacity;
		if (file.fail()) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : capacity";
			return;
		}

		file >> numberOfItems;
		if (file.fail() || numberOfItems <= 0) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : number of items";
			return;
		}

		items = new KSItems(numberOfItems);

		unsigned weight, value;
		for (int i = 0; i < numberOfItems; i++) {
			file >> weight >> value;
			if (file.fail()) {
				file.close();
				errorFlag = true;
				errorMessage = "File read error : items data";

				delete items;
				return;
			} else
				items->addItem(weight, value);
		}

		file.close();
	} else {
		errorFlag = true;
		errorMessage = "File read error : file open";
	}
}

KSFileReader::KSFileReader(std::string filename) : capacity(0), items(nullptr), errorFlag(false) {
	read(filename);
}
