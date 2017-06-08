#include "TSGreedy.h"
#include <climits>
#include <sstream>
#include <iomanip>

void TSGreedy::execute(AdjacencyMatrix * cities) {
	delete result;
	result = new TSPath(cities->getSize() + 1);
	unsigned totalDistance = 0;

	bool* visited = new bool[cities->getSize()];

	// 0 is always the first visited city
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
				// destination city unvisited and closer than previous best 
				bestDistance = cities->getEdge(lastVisited, dest);
				bestNode = dest;
			}
		}

		// best node is saved to final path and marked visited
		visited[bestNode] = true;
		lastVisited = bestNode;
		totalDistance += bestDistance;
		result->add(bestNode);
	}

	// add 0 and distance to it to close the path
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
