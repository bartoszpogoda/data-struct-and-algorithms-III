#pragma once
#include "TSAlgorithm.h"
#include "AdjacencyMatrix.h"

class TSGreedy : public TSAlgorithm {
public:
	void execute(AdjacencyMatrix* cities);
	std::string toString();
};
