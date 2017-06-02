#pragma once
#include "TSAlgorithm.h"
#include "AdjacencyMatrix.h"

class TSGreedy : TSAlgorithm {
public:
	void execute(AdjacencyMatrix* cities);
	std::string toString();
};
