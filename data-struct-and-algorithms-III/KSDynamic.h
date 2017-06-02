#pragma once
#include "KSAlgorithm.h"

class KSDynamic : public KSAlgorithm {
public:
	void execute(KSItems* items, unsigned capacity);
	std::string toString();
};
