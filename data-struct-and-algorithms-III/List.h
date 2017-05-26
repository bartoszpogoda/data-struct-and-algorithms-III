#pragma once
#include "ListNode.h"
#include <iostream>

template <class Element>
class List {
	ListNode<Element>* head;
	ListNode<Element>* tail;
	int currentSize;

public:
	List() : currentSize(0), head(nullptr), tail(nullptr) {}
	~List();

	int size() { return currentSize; }

	void addEnd(Element element);
	Element get(int position);
};


template<class Element>
inline List<Element>::~List() {
	if (head == nullptr)
		return;

	ListNode<Element>* iterator = head;
	ListNode<Element>* preIterator = head;

	while (iterator->next != nullptr) {
		preIterator = iterator;
		iterator = iterator->next;

		delete preIterator;
	}

	delete iterator;
}

template<class Element>
inline void List<Element>::addEnd(Element element) {
	ListNode<Element>* newNode = new ListNode<Element>(element);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}

	currentSize++;
}

template<class Element>
inline Element List<Element>::get(int position) {
	if (currentSize == 0 || position >= currentSize)
		return Element();

	ListNode<Element>* iterator = head;

	while (position--)
		iterator = iterator->next;

	return iterator->element;
}
