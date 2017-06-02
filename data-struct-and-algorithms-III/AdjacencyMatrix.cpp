#include "AdjacencyMatrix.h"
#include <sstream>
#include <iomanip>

AdjacencyMatrix::AdjacencyMatrix(int n) : n(n), matrix(new unsigned*[n]) {
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new unsigned[n];

		for (size_t j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix() {
	for (size_t i = 0; i < n; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = nullptr;
}

void AdjacencyMatrix::addEdge(unsigned start, unsigned end, unsigned weight) {
	matrix[start][end] = weight;
}

unsigned AdjacencyMatrix::getEdge(unsigned start, unsigned end) {
	return matrix[start][end];
}

std::string AdjacencyMatrix::toString() {
	std::stringstream out;

	int argWidth = 4;

	// indexes row
	out << std::setw(argWidth) << std::setfill(' ') << "" << "|";
	for (size_t i = 0; i < n; i++)
		out << std::setw(argWidth) << i << "|";
	out << std::endl;

	// +---+.... row
	for (int i = -1; i < n; i++)
		out << std::setw(argWidth) << std::setfill('-') << "" << "+";
	out << std::endl;

	// main data loop
	for (size_t i = 0; i < n; i++) {
		out << std::setw(argWidth) << std::setfill(' ') << i << "|";

		for (size_t j = 0; j < n; j++)
			out << std::setw(argWidth) << std::to_string(matrix[i][j]) << " ";

		out << std::endl;
	}

	out << std::endl;
	return out.str();
}