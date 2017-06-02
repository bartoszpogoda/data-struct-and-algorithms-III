#pragma once
#include "TSAlgorithm.h"
#include "AdjacencyMatrix.h"

class TSLocalSearch3Opt : public TSAlgorithm {
	TSPath* initPath;
public:
	void execute(AdjacencyMatrix* cities);

	void setInitPath(TSPath* initPath) { this->initPath = initPath; }

	std::string toString();
};
