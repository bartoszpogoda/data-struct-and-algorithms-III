#pragma once
#include <string>

class AdjacencyMatrix{
protected:
	unsigned** matrix;
	int n;
public:
	AdjacencyMatrix(int n);
	~AdjacencyMatrix();

	int getSize() { return n; }

	void addEdge(unsigned start, unsigned end, unsigned weight);
	unsigned getEdge(unsigned start, unsigned end);

	std::string AdjacencyMatrix::toString();
};