#pragma once
#include "TSAlgorithm.h"
#include "AdjacencyMatrix.h"

class TSLocalSearch3Opt : public TSAlgorithm {
	TSPath* initPath;

	unsigned* generateRandomPath(unsigned pathSize);
	unsigned* swapPath(unsigned* path, unsigned pathSize, unsigned i, unsigned j, unsigned k);

public:
	void execute(AdjacencyMatrix* cities);

	void setInitPath(TSPath* initPath) { this->initPath = initPath; }

	std::string toString();
};
