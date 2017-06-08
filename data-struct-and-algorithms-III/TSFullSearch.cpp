#include "TSFullSearch.h"
#include <climits>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>


TSFullSearch::RecursionStepResult TSFullSearch::recStep(AdjacencyMatrix * cities, unsigned* unvisited, unsigned unvisitedSize, unsigned previousNode) {
	if (unvisitedSize == 0) {
		return RecursionStepResult(nullptr, 0, cities->getEdge(previousNode,0));
	}

	unsigned bestDistance = UINT_MAX;
	unsigned *bestPath = nullptr;
	unsigned bestPathSize;

	for (size_t i = 0; i < unvisitedSize; i++) {
		unsigned nodeId = unvisited[i];
		unvisited[i] = unvisited[unvisitedSize - 1];

		// recursion with unvisitedSize - 1
		RecursionStepResult result = recStep(cities, unvisited, unvisitedSize - 1, nodeId);

		if (result.distance + cities->getEdge(previousNode, nodeId) < bestDistance) {
			bestDistance = result.distance + cities->getEdge(previousNode, nodeId);

			bestPathSize = result.pathSize + 1;
			delete[] bestPath;
			bestPath = new unsigned[bestPathSize];
			for (size_t j = 0; j < bestPathSize - 1; j++) {
				bestPath[j] = result.path[j];
			}
			bestPath[bestPathSize - 1] = nodeId;
		}

		// return state of unvisited before next iteration
		unvisited[i] = nodeId;
	}

	return RecursionStepResult(bestPath, bestPathSize, bestDistance);
}

void TSFullSearch::execute(AdjacencyMatrix * cities) {
	delete result;
	result = nullptr;

	// all nodes (except for node 0) are unvisited at beginning
	unsigned unvisitedSize = cities->getSize() - 1;
	unsigned *unvisited = new unsigned[unvisitedSize];
	for (size_t i = 0; i < unvisitedSize; i++) {
		unvisited[i] = i+1;
	}

	unsigned startNode = 0;

	// recursion 
	RecursionStepResult recursionResult = recStep(cities, unvisited, unvisitedSize, startNode);

	// save result (in reversed order) append start node to finish loop
	result = new TSPath(recursionResult.pathSize + 2, recursionResult.distance);
	result->add(startNode);
	for (int i = recursionResult.pathSize - 1 ; i >= 0; i--) {
		result->add(recursionResult.path[i]);
	}
	result->add(startNode);

	delete[] unvisited;
}

std::string TSFullSearch::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Full Search" << std::endl;
	out << std::setfill('-') << std::setw(19) << "" << std::endl;
	out << (result == nullptr ? "No result" : result->toString());

	return out.str();
}
