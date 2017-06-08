#pragma once
#include "KSItems.h"
#include "AdjacencyMatrix.h"

class RandomInstanceGenerator {
public:
	KSItems* generateKSItems(unsigned n, unsigned capacity);
	AdjacencyMatrix* generateAdjacencyMatrix(unsigned n);
};