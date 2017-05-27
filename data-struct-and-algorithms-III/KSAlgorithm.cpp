#include "KSAlgorithm.h"

KSKnapsack * KSAlgorithm::getResult() {
	KSKnapsack* result = this->result;
	this->result = nullptr;
	return result;
}
