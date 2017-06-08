#pragma once
#include <string>

class TSPath {
	unsigned currentSize, size, *path;
	unsigned length;
public:
	TSPath(unsigned size, unsigned length) : size(size), currentSize(0), path(new unsigned[size]), length(length) {}
	TSPath(unsigned size) : TSPath(size, 0) {}
	TSPath(unsigned* path, unsigned size) : path(path), size(size), currentSize(size), length(0) {}
	~TSPath() { delete[] path; }

	void add(unsigned pathNode);
	void setLength(unsigned length) { this->length = length; }

	unsigned getsize() { return currentSize; }
	unsigned get(unsigned i) { return path[i]; }

	std::string toString();
};