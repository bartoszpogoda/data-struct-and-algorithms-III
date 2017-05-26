#pragma once
#include "KSAlgorithm.h"

class KSDynamic : KSAlgorithm {
public:
	void execute(KSItems* items, unsigned capacity);
	std::string toString();
};
