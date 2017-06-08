#pragma once

#include "Timer.h"
#include "RandomInstanceGenerator.h"
#include "KSFullSearch.h"
#include "KSDynamic.h"
#include "KSGreedy.h"

#include "TSFullSearch.h"
#include "TSGreedy.h"
#include "TSLocalSearch3Opt.h"

class PerformanceTester {
	// hard coded parameters
	unsigned kspN[5] = {1000,3000,5000,7000,9000};
	unsigned kspNFullSearch[5] = { 50, 60, 70, 80, 90};
	unsigned kspCapacities[3] = { 500, 1000, 1500 };

	//unsigned tspN[5] = {50,60,70,80,90};
	unsigned tspN[5] = {100,200,300,400,500};
	unsigned tspNFullSearch[5] = { 6,7,8,9,10 };

	int iterations = 100;

	RandomInstanceGenerator generator;
	Timer timer;

	KSAlgorithm* ksAlgorithm;
	TSAlgorithm* tsAlgorithm;

public:
	PerformanceTester() : ksAlgorithm(nullptr), tsAlgorithm(nullptr) {};
	~PerformanceTester();

	void runKSDynamic();
	void runKSFullSearch();
	void runKSGreedy();

	void runKSFullSearchProgressive();
	void runTSFullSearchProgressive();

	void runTSLocalSearch();
	void runTSFullSearch();
	void runTSGreedy();
};