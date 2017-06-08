#include "RandomInstanceGenerator.h"

KSItems * RandomInstanceGenerator::generateKSItems(unsigned n, unsigned capacity) {
	KSItems* items = new KSItems(n);
	unsigned totalWeight = 0;

	unsigned weightRange = capacity;
	unsigned valueRange = 100;

	// N - 1 items randomly
	for (size_t i = 0; i < n - 1; i++) {
		unsigned weight = 1 + rand() % weightRange;
		unsigned value = 1 + rand() % valueRange;

		items->addItem(weight, value);
		totalWeight += weight;
	}

	// last item to ensure total weight > capacity
	if (totalWeight <= capacity) {
		unsigned weight = (capacity - totalWeight + 1) + rand() % weightRange;
		unsigned value = 1 + rand() % valueRange;

		items->addItem(weight, value);
	} else {
		unsigned weight = 1 + rand() % weightRange;
		unsigned value = 1 + rand() % valueRange;

		items->addItem(weight, value);
	}
	
	return items;
}

AdjacencyMatrix * RandomInstanceGenerator::generateAdjacencyMatrix(unsigned n) {
	AdjacencyMatrix* cities = new AdjacencyMatrix(n);

	unsigned distanceRange = 100;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (i != j) cities->addEdge(i, j, 1 + rand() % distanceRange);
		}
	}

	return cities;
}
