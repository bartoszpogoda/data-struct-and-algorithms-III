#include "TSAlgorithm.h"

TSPath * TSAlgorithm::getResult() {
	TSPath* result = this->result;
	this->result = nullptr;
	return result;
}
