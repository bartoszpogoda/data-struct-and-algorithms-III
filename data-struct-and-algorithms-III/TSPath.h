#include <string>

/*
	A structure to keep results for Travelling salesman problem
*/
class TSPath {

	unsigned currentSize, size, *path;
	unsigned length;

public:
	TSPath(unsigned size, unsigned length) : size(size), currentSize(0), path(new unsigned[size]), length(length) {}
	~TSPath() { delete[] path; }

	void add(unsigned pathNode);

	unsigned getsize() { return currentSize; }
	unsigned get(unsigned i) { return path[i]; }

	std::string toString();
};