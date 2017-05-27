#pragma once
#include "KSKnapsack.h"
#include "KSItems.h"

#include <string>

/*
	KSAlgorithm executes knapsack algorithm and keeps the result's reference
	The reference is forgoten on getResult() call so the KSKnapsack
	must be then dealocated outside
	KSAlgorithm dealocates result (if wasn't accessed) on obj destruction
*/
class KSAlgorithm {
protected:
	KSKnapsack* result;
public:
	KSAlgorithm() : result(nullptr) {}
	virtual ~KSAlgorithm() { delete result; }

	KSKnapsack* getResult();

	virtual void execute(KSItems* items, unsigned capacity) = 0;
	virtual std::string toString() = 0;
};