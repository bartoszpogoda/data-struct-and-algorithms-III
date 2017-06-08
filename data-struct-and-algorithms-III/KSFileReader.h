#pragma once
#include <string>
#include "KSItems.h"

class KSFileReader {
	unsigned capacity;
	KSItems* items;
	bool errorFlag;
	std::string errorMessage;

	void read(std::string filename);

public:
	KSFileReader(std::string filename);
	~KSFileReader() { delete[] items; }

	unsigned getCapacity() { return capacity; }
	KSItems* getItems();

	// read status
	bool success() { return !errorFlag; }
	std::string getErrorMessage() { return errorMessage; }
};