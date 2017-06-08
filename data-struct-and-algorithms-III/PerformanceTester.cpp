#include "PerformanceTester.h"


PerformanceTester::~PerformanceTester() {
	delete ksAlgorithm;
	delete tsAlgorithm;
}

void PerformanceTester::runKSDynamic() {
	delete ksAlgorithm;
	ksAlgorithm = new KSDynamic();

	std::cout << "KSDynamic" << std::endl;
	for each (unsigned n in kspN) {
		for each (unsigned capacity in kspCapacities) {
			timer.resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				KSItems* randomItems = generator.generateKSItems(n, capacity);

				timer.startTimer();
				ksAlgorithm->execute(randomItems, capacity);
				timer.endTimer();

				delete ksAlgorithm->getResult();
				delete randomItems;
			}
			timer.divideMemory(iterations);

			std::cout << timer.timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}
}

void PerformanceTester::runKSFullSearch() {
	delete ksAlgorithm;
	ksAlgorithm = new KSFullSearch();

	std::cout << "KSFullSearch" << std::endl;
	for each (unsigned n in kspNFullSearch) {
		for each (unsigned capacity in kspCapacities) {
			timer.resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				KSItems* randomItems = generator.generateKSItems(n, capacity);

				timer.startTimer();
				ksAlgorithm->execute(randomItems, capacity);
				timer.endTimer();

				delete ksAlgorithm->getResult();
				delete randomItems;
			}
			timer.divideMemory(iterations);

			std::cout << timer.timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}
}

void PerformanceTester::runKSGreedy() {
	delete ksAlgorithm;
	ksAlgorithm = new KSGreedy(new KSGreedyDecisionValue());

	std::cout << "KSGreedyValue" << std::endl;
	for each (unsigned n in kspN) {
		for each (unsigned capacity in kspCapacities) {
			timer.resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				KSItems* randomItems = generator.generateKSItems(n, capacity);

				timer.startTimer();
				ksAlgorithm->execute(randomItems, capacity);
				timer.endTimer();

				delete ksAlgorithm->getResult();
				delete randomItems;
			}
			timer.divideMemory(iterations);

			std::cout << timer.timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}

	delete ksAlgorithm;
	ksAlgorithm = new KSGreedy(new KSGreedyDecisionValueToWeight());

	std::cout << "KSGreedyValueToWeight" << std::endl;
	for each (unsigned n in kspN) {
		for each (unsigned capacity in kspCapacities) {
			timer.resetMemory();

			for (size_t i = 0; i < iterations; i++) {

				KSItems* randomItems = generator.generateKSItems(n, capacity);

				timer.startTimer();
				ksAlgorithm->execute(randomItems, capacity);
				timer.endTimer();

				delete ksAlgorithm->getResult();
				delete randomItems;
			}
			timer.divideMemory(iterations);

			std::cout << timer.timeMiliSecondsMemory() << ";";
		}
		std::cout << std::endl;
	}
}

void PerformanceTester::runKSFullSearchProgressive() {
	delete ksAlgorithm;
	ksAlgorithm = new KSFullSearch();
	unsigned capacity = 1000;
	unsigned n = 185;

	std::cout << "KSFullSearchProgressive " << n << "..." << std::endl;
	while (true){
		std::cout << n << ";";
		KSItems* randomItems = generator.generateKSItems(n, capacity);

		timer.startTimer();
		ksAlgorithm->execute(randomItems, capacity);

		KSKnapsack* result =  ksAlgorithm->getResult();
		std::cout << "Result: " << result->toString() << std::endl;
		timer.endTimer();

		delete result;
		delete randomItems;

		std::cout << timer.timeSeconds() << std::endl;
		n++;
	}
	std::cout << std::endl;
}

void PerformanceTester::runTSFullSearchProgressive() {
	delete tsAlgorithm;
	tsAlgorithm = new TSFullSearch();
	unsigned n = 13;

	std::cout << "KSFullSearchProgressive " << n << "..." << std::endl;
	while (true) {
		std::cout << n << ";";
		AdjacencyMatrix* randomCities = generator.generateAdjacencyMatrix(n);

		std::cout << "Generated instance" << std::endl;

		timer.startTimer();
		tsAlgorithm->execute(randomCities);
		timer.endTimer();

		TSPath* result = tsAlgorithm->getResult();
		std::cout << "Result: " << result->toString() << std::endl;

		delete result;
		delete randomCities;

		std::cout << timer.timeSeconds() << std::endl;
		n++;
	}
	std::cout << std::endl;
}

void PerformanceTester::runTSLocalSearch() {
	delete tsAlgorithm;
	tsAlgorithm = new TSLocalSearch3Opt();

	std::cout << "TSLocalSearch3Opt" << std::endl;
	for each (unsigned n in tspN) {
		timer.resetMemory();

		for (size_t i = 0; i < iterations; i++) {

			AdjacencyMatrix* randomCities = generator.generateAdjacencyMatrix(n);

			timer.startTimer();
			tsAlgorithm->execute(randomCities);
			timer.endTimer();

			delete tsAlgorithm->getResult();
			delete randomCities;
		}
		timer.divideMemory(iterations);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}
	std::cout << std::endl;
}

void PerformanceTester::runTSFullSearch() {
	delete tsAlgorithm;
	tsAlgorithm = new TSFullSearch();

	std::cout << "TSFullSearch" << std::endl;
	for each (unsigned n in tspNFullSearch) {
		timer.resetMemory();

		for (size_t i = 0; i < iterations; i++) {

			AdjacencyMatrix* randomCities = generator.generateAdjacencyMatrix(n);

			timer.startTimer();
			tsAlgorithm->execute(randomCities);
			timer.endTimer();

			delete tsAlgorithm->getResult();
			delete randomCities;
		}
		timer.divideMemory(iterations);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}
	std::cout << std::endl;
}

void PerformanceTester::runTSGreedy() {
	delete tsAlgorithm;
	tsAlgorithm = new TSGreedy();

	std::cout << "TSGreedy" << std::endl;
	for each (unsigned n in tspN) {
		timer.resetMemory();

		for (size_t i = 0; i < iterations; i++) {

			AdjacencyMatrix* randomCities = generator.generateAdjacencyMatrix(n);

			timer.startTimer();
			tsAlgorithm->execute(randomCities);
			timer.endTimer();

			delete tsAlgorithm->getResult();
			delete randomCities;
		}
		timer.divideMemory(iterations);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}
	std::cout << std::endl;
}
