#include "TSLocalSearch3Opt.h"
#include <climits>
#include <sstream>
#include <iomanip>

unsigned * TSLocalSearch3Opt::generateRandomPath(unsigned pathSize) {
	unsigned* path = new unsigned[pathSize];

	// the first and the last nodes
	path[0] = path[pathSize - 1] = 0;

	// rest of the nodes 1...pathSize-1
	unsigned unusedSize = pathSize - 2;
	unsigned* unused = new unsigned[unusedSize];
	for (size_t i = 0; i < unusedSize; i++) {
		unused[i] = i + 1;
	}

	unsigned i = 1,randomIndex = -1;
	while (unusedSize > 0) {

		randomIndex = rand() % unusedSize;
		path[i++] = unused[randomIndex];
		unused[randomIndex] = unused[unusedSize - 1];
		unusedSize--;
	}

	delete[] unused;
	return path;
}
/* 
	[ start..i ][i][ i..j ][j][ j..k ][k][ k..end]
			to
	[ start..i ][i][ j..k ][k][ i..j ][j][ k..end]
*/
unsigned * TSLocalSearch3Opt::swapPath(unsigned * path, unsigned pathSize, unsigned bestI, unsigned bestJ, unsigned bestK) {
	// execute swap
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
	return newPath;
}

void TSLocalSearch3Opt::execute(AdjacencyMatrix * cities) {
	delete result;

	unsigned pathSize = cities->getSize() + 1;
	unsigned* path;

	if (initPath != nullptr) {
		// preset init path
		path = new unsigned[pathSize];
		for (size_t i = 0; i < pathSize; i++)
			path[i] = initPath->get(i);

	} else {
		// random init path
		path = generateRandomPath(pathSize);
	}

	int iterationMinChange = 0;
	int bestI, bestJ, bestK;
	do {
		iterationMinChange = 0;
		bestI = bestJ = bestK = -1;
		for (size_t i = 1; i < pathSize - 5; i++) {
			for (size_t j = i + 2; j < pathSize - 3; j++) {
				for (size_t k = j + 2; k < pathSize - 1; k++) {
					// iteration through all possible 3's of edges selections
					// last one: 0 -> a -> ... -> [b] -> c -> [d] -> e -> [f] -> 0
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
			path = swapPath(path, pathSize, bestI, bestJ, bestK);
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

	out << "Solution" << std::endl << "Local Search 3-opt" << (initPath == nullptr ? " (random init)" : " (preset init)") << std::endl;
	out << std::setfill('-') << std::setw(19) << "" << std::endl;
	out << (result == nullptr ? "No result" : result->toString());

	return out.str();
}
