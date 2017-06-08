#pragma once

#include "TSPath.h"
#include "AdjacencyMatrix.h"
#include <string>

/*
	TSAlgorithm executes traveling salesman problem algorithm and keeps the result's reference
	The reference is forgoten on getResult() call so the TSPath
	must be then dealocated outside
	TSAlgorithm dealocates result (if wasn't accessed) on obj destruction
*/
class TSAlgorithm {
protected:
	TSPath* result;
public:
	TSAlgorithm() : result(nullptr) {}
	virtual ~TSAlgorithm() { delete result; }

	TSPath* getResult();

	virtual void execute(AdjacencyMatrix* cities) = 0;
	virtual std::string toString() = 0;
};