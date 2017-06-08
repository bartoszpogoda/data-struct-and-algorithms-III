#pragma once
#include "KSItem.h"

class KSGreedyDecision {
public:
	// returns true if item a is classified as "better"
	virtual bool decide(KSItem a, KSItem b) = 0;
	virtual std::string toString() = 0;
};

class KSGreedyDecisionValue : public KSGreedyDecision {
	bool decide(KSItem a, KSItem b) { return a.getValue() >= b.getValue(); }
	std::string toString() { return "Value"; }
};

class KSGreedyDecisionValueToWeight : public KSGreedyDecision {
	bool decide(KSItem a, KSItem b) { return ((double)a.getValue()) / (a.getWeight()) >= ((double)b.getValue()) / (b.getWeight()); }
	std::string toString() { return "Value/Weight"; }
};