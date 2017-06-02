#include "TSFullSearch.h"
#include <climits>
#include <sstream>
#include <string>
#include <iomanip>


TSFullSearch::RecursionStepResult TSFullSearch::recStep(AdjacencyMatrix * cities, unsigned* unvisited, unsigned unvisitedSize, unsigned previousNode) {
	if (unvisitedSize == 0) {
		return RecursionStepResult(nullptr, 0, 0);
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

	// variables and structures to keep track about current best path
	unsigned bestDistance = UINT_MAX;
	unsigned bestPathSize;
	unsigned *bestPath = nullptr;

	// all nodes are unvisited at beginning
	unsigned unvisitedSize = cities->getSize();
	unsigned *unvisited = new unsigned[unvisitedSize];
	for (size_t i = 0; i < cities->getSize(); i++) {
		unvisited[i] = i;
	}

	// start recurrency for each (start) node - find the best path
	for (size_t i = 0; i < unvisitedSize; i++) {
		unsigned startNode = unvisited[i];
		unvisited[i] = unvisited[unvisitedSize - 1];

		// recursion with unvisitedSize - 1
		RecursionStepResult result = recStep(cities, unvisited, unvisitedSize - 1, startNode);
		
		unsigned resultPathLastNode = result.path[0];

		if (result.distance + cities->getEdge(resultPathLastNode, startNode) < bestDistance) {
			bestDistance = result.distance + cities->getEdge(resultPathLastNode, startNode);

			bestPathSize = result.pathSize + 1;
			delete[] bestPath;
			bestPath = new unsigned[bestPathSize];
			for (size_t j = 0; j < bestPathSize - 1; j++) {
				bestPath[j] = result.path[j];
			}
			bestPath[bestPathSize - 1] = startNode;
		}

		// return state of unvisited before next iteration
		unvisited[i] = startNode;
	}

	// save result (in reversed order) append start node to finish loop
	result = new TSPath(bestPathSize + 1, bestDistance);
	for (int i = bestPathSize - 1 ; i >= 0; i--) {
		result->add(bestPath[i]);
	}
	result->add(bestPath[bestPathSize - 1]);
}

std::string TSFullSearch::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Full Search" << std::endl;
	out << std::setfill('-') << std::setw(19) << "" << std::endl;
	out << (result == nullptr ? "No result" : result->toString());

	return out.str();
}
