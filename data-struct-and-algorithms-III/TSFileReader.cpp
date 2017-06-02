#include "TSFileReader.h"
#include <fstream>

void TSFileReader::read(std::string filename) {
	std::ifstream file = std::ifstream(filename);
	errorFlag = false;
	unsigned numberOfCities = 0;

	if (cities != nullptr) {
		return;
	}

	if (file.is_open()) {

		file >> numberOfCities;
		if (file.fail()) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : number of cities";
			return;
		}

		
		cities = new AdjacencyMatrix(numberOfCities);

		unsigned distance;
		for (int i = 0; i < numberOfCities; i++) {
			for (int j = 0; j < numberOfCities; j++) {
				file >> distance;
				if (file.fail()) {
					file.close();
					errorFlag = true;
					errorMessage = "File read error : cities data";

					delete cities;
					return;
				} else
					cities->addEdge(i, j, distance);
			}
		}

		file.close();
	} else {
		errorFlag = true;
		errorMessage = "File read error : file open";
	}
}

TSFileReader::TSFileReader(std::string filename) : cities(nullptr), errorFlag(false){
	read(filename);
}

AdjacencyMatrix * TSFileReader::getCities() {
	AdjacencyMatrix* cities = this->cities;
	this->cities = nullptr;
	return cities;
}
