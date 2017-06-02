#include "PerformanceTester.h"
#include "CLInterface.h"
#include <iostream>

int main() {
	CLInterface::enter();

	PerformanceTester perf;
	perf.runKSDynamic();
	perf.runKSGreedy();

	perf.runTSLocalSearch();
	perf.runTSGreedy();

	perf.runKSFullSearch();
	perf.runTSFullSearch();


	int x;
	std::cin >> x;
}