#pragma once
#include <string>
#include "AdjacencyMatrix.h"

class TSFileReader {
	AdjacencyMatrix* cities;
	bool errorFlag;
	std::string errorMessage;

	void read(std::string filename);

public:
	TSFileReader(std::string filename);
	~TSFileReader() { delete[] cities; }

	AdjacencyMatrix* getCities() { return cities; cities = nullptr; }

	// read status
	bool success() { return !errorFlag; }
	std::string getErrorMessage() { return errorMessage; }
};