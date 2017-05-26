#include "KSKnapsack.h"
#include <iostream>


int main() {
	KSKnapsack knap;

	knap.addItem(0, 42, 21);
	knap.addItem(2, 51, 11);

	std::cout << knap.toString();

	int x;
	std::cin >> x;
}