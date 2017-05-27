#pragma once
#include "KSAlgorithm.h"
#include "KSItem.h"

class KSItemDecision;

class KSGreedy : KSAlgorithm {
	KSItemDecision& strategy;
public:
	void setPickStrategy(KSItemDecision& strategy) { this->strategy = strategy; }

	void execute(KSItems* items, unsigned capacity);
	std::string toString();
};

class KSItemDecision {
public:
	// returns true if item a is classified as "better"
	virtual bool decide(KSItem a, KSItem b) = 0;	
};

class KSItemDecisionValue : KSItemDecision {
	bool decide(KSItem a, KSItem b) { return a.getValue() > b.getValue; }
};

class KSItemDecisionValueToWeight : KSItemDecision {
	bool decide(KSItem a, KSItem b) { return (a.getValue())/(a.getWeight()) > (b.getValue())/(b.getWeight()); }
};