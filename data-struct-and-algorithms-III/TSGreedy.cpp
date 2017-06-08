#include "TSGreedy.h"
#include <climits>
#include <sstream>
#include <iomanip>

void TSGreedy::execute(AdjacencyMatrix * cities) {
	delete result;
	result = new TSPath(cities->getSize() + 1);
	unsigned totalDistance = 0;

	bool* visited = new bool[cities->getSize()];

	result->add(0);
	unsigned lastVisited = 0;

	visited[0] = true;
	for (size_t i = 1; i < cities->getSize(); i++) {
		visited[i] = false;
	}

	for (size_t i = 0; i < cities->getSize() - 1; i++) {

		int bestDistance = UINT_MAX;
		int bestNode = -1;

		for (size_t dest = 1; dest < cities->getSize(); dest++) {	// could also hold unvisited cities and access only them
			if (!visited[dest] && bestDistance > cities->getEdge(lastVisited, dest)) {
				// source unvisited and closer than previous best 
				bestDistance = cities->getEdge(lastVisited, dest);
				bestNode = dest;
			}
		}

		visited[bestNode] = true;
		lastVisited = bestNode;

		totalDistance += bestDistance;
		result->add(bestNode);
	}

	totalDistance += cities->getEdge(lastVisited, 0);
	result->add(0);
	result->setLength(totalDistance);

	delete[] visited;
}

std::string TSGreedy::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Greedy" << std::endl;
	out << std::setfill('-') << std::setw(19) << "" << std::endl;
	out << (result == nullptr ? "No result" : result->toString());

	return out.str();
}
