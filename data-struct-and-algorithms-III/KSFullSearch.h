#pragma once
#include "KSAlgorithm.h"

class KSFullSearch : public KSAlgorithm {
	class RecursionStepResult;
	RecursionStepResult recStep(KSItems* items, unsigned remainingCapacity, unsigned i);

public:
	void execute(KSItems* items, unsigned capacity);
	std::string toString();
};

class KSFullSearch::RecursionStepResult{
public:
	unsigned value;
	unsigned mask;

	RecursionStepResult(unsigned value, unsigned mask) : value(value), mask(mask) {};
};
