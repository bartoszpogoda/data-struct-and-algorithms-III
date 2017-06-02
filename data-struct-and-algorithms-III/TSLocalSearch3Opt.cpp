#include "TSLocalSearch3Opt.h"
#include <climits>
#include <sstream>
#include <iomanip>
#include <iostream>
void TSLocalSearch3Opt::execute(AdjacencyMatrix * cities) {
	delete result;

	unsigned pathSize = initPath->getsize();
	unsigned* path = new unsigned[pathSize];
	for (size_t i = 0; i < pathSize; i++) {
		path[i] = initPath->get(i);
	}
	//unsigned pathSize = cities->getSize() + 1;
	//unsigned* path = new unsigned[pathSize];

	/*path[0] = path[pathSize-1] =  0;

	// for debug 
	for (size_t i = 1; i < pathSize - 1; i++) {
		path[i] = i;
	}*/

	// 0 -> a -> [b] -> c -> [d] -> e -> [f] -> 0
	int iterationMinChange = 0;
	int bestI, bestJ, bestK;
	do {
		iterationMinChange = 0;
		bestI = bestJ = bestK = -1;
		for (size_t i = 1; i < pathSize - 5; i++) {
			for (size_t j = i + 2; j < pathSize - 3; j++) {
				for (size_t k = j + 2; k < pathSize - 1; k++) {
					// iteration through all possible 3's of edges
					int oldDist = cities->getEdge(path[i], path[i + 1])
						+ cities->getEdge(path[j], path[j + 1])
						+ cities->getEdge(path[k], path[k + 1]);
					int newDist = cities->getEdge(path[i], path[j + 1])
						+ cities->getEdge(path[k], path[i + 1])
						+ cities->getEdge(path[j], path[k + 1]);
					int delta = newDist - oldDist;

					if (delta < iterationMinChange) {
						iterationMinChange = delta;
						bestI = i; bestJ = j; bestK = k;
					}
				}
			}
		}

		if (iterationMinChange < 0) {
			// swap with the best one
			unsigned* newPath = new unsigned[pathSize];
			unsigned dest = 0;

			for (size_t i = 0; i <= bestI; i++)
				newPath[dest++] = path[i];
			for (size_t i = bestJ + 1; i <= bestK; i++)
				newPath[dest++] = path[i];
			for (size_t i = bestI + 1; i <= bestJ; i++)
				newPath[dest++] = path[i];
			for (size_t i = bestK + 1; i < pathSize; i++)
				newPath[dest++] = path[i];

			delete[] path;
			path = newPath;
		}

	} while (iterationMinChange < 0);

	result = new TSPath(path, pathSize);

	unsigned totalLength = 0;
	for (size_t i = 0; i < pathSize - 1; i++) {
		totalLength += cities->getEdge(path[i], path[i + 1]);
	}
	result->setLength(totalLength); 
}

std::string TSLocalSearch3Opt::toString() {
	std::stringstream out;

	out << "Solution" << std::endl << "Local Search 2-opt" << std::endl;
	out << std::setfill('-') << std::setw(19) << "" << std::endl;
	out << (result == nullptr ? "No result" : result->toString());

	return out.str();
}
