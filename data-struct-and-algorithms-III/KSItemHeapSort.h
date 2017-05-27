#pragma once

#include "KSItem.h"
#include "KSGreedyDecision.h"

/*
	doesn't dealocate decision
	it builds minimum heap, but then pops root in loop in reverse order
	so the result is ordered properly based on KSGreedyDecision strategy
*/
class KSItemHeapSort {
	KSGreedyDecision* decision;

	int parent(int nodeId) { return (nodeId - 1) / 2; }
	int leftChild(int nodeId) { return 2 * nodeId + 1; }
	int rightChild(int nodeId) { return 2 * nodeId + 2; }

	void fixDown(KSItem* elements, int size, int nodeId);
public:
	KSItemHeapSort(KSGreedyDecision* decision) : decision(decision) {}
	KSItem* sort(KSItem* elements, int size);
};