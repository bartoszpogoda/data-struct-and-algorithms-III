#pragma once
#include "TSAlgorithm.h"
#include "AdjacencyMatrix.h"

class TSFullSearch : public TSAlgorithm {
	class RecursionStepResult;
	RecursionStepResult recStep(AdjacencyMatrix* cities, unsigned *unvisited, unsigned unvisitedSize, unsigned previousNode);

public:
	void execute(AdjacencyMatrix* cities);
	std::string toString();
};

class TSFullSearch::RecursionStepResult {
public:
	unsigned* path;
	unsigned pathSize;
	unsigned distance;

	RecursionStepResult(unsigned* path, unsigned pathSize, unsigned distance) : path(path), pathSize(pathSize), distance(distance) { };
	~RecursionStepResult() { delete[] path; }
};