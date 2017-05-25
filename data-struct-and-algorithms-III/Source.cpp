#include "KSItems.h"
#include <iostream>


int main() {
	KSItems ksItems = KSItems(2);
	ksItems.addItem(1, 3);
	ksItems.addItem(2, 4);

	std::cout << ksItems.toString();

	int x;
	std::cin >> x;
}