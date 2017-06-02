#pragma once
#include "KSAlgorithm.h"
#include "KSGreedyDecision.h"
#include <string>

/*
	Pointer to decision strategy is dealocated inside of this class
	both on strategy change and destruction
*/
class KSGreedy : public KSAlgorithm {
	// swichable with strategy pattern
	KSGreedyDecision* itemDecision;
public:
	KSGreedy() : KSAlgorithm(), itemDecision(nullptr) {}
	KSGreedy(KSGreedyDecision* itemDecision) : KSAlgorithm(), itemDecision(itemDecision) {}
	~KSGreedy() { delete itemDecision; }

	void setItemDecision(KSGreedyDecision* itemDecision) { delete this->itemDecision; this->itemDecision = itemDecision; }

	void execute(KSItems* items, unsigned capacity);
	std::string toString();
};
