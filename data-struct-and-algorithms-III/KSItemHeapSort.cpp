#include "KSItemHeapSort.h"

//dbg
#include <iostream>

void KSItemHeapSort::fixDown(KSItem * elements, int size, int nodeId) {
	while (leftChild(nodeId) < size) {
		// if left child has less value
		if (!decision->decide(elements[leftChild(nodeId)],elements[nodeId])) {
			// if right child exists and has less value than left
			if (rightChild(nodeId) < size && !decision->decide(elements[rightChild(nodeId)],elements[leftChild(nodeId)])) {
				// swap with right child
				KSItem dataHolder = elements[nodeId];
				elements[nodeId] = elements[rightChild(nodeId)];
				elements[rightChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = rightChild(nodeId);
			} else {
				// swap with left child
				KSItem dataHolder = elements[nodeId];
				elements[nodeId] = elements[leftChild(nodeId)];
				elements[leftChild(nodeId)] = dataHolder;

				// for next iteration
				nodeId = leftChild(nodeId);
			}

		} // if right child exists and has less value
		else if (rightChild(nodeId) < size && !decision->decide(elements[rightChild(nodeId)],elements[nodeId])) {
			// swap with right child
			KSItem dataHolder = elements[nodeId];
			elements[nodeId] = elements[rightChild(nodeId)];
			elements[rightChild(nodeId)] = dataHolder;

			// for next iteration
			nodeId = rightChild(nodeId);
		} else {
			// heap fixed
			return;
		}
	}
}

KSItem * KSItemHeapSort::sort(KSItem * elements, int size) {
	if (decision == nullptr)
		return nullptr;

	KSItem* result = new KSItem[size];
	// make copy
	for (int i = 0; i < size; i++) {
		result[i] = elements[i];
	}

	// fix heap - start from last parent
	int parentIteration = parent(size - 1);
	do {
		fixDown(result, size, parentIteration);

	} while (--parentIteration >= 0);

	// 

	while (size > 0) {
		KSItem root = result[0];
		result[0] = result[size - 1];
		result[size - 1] = root;

		size--;
		fixDown(result, size, 0);
	}


	return result;
}
