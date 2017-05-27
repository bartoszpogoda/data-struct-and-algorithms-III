#pragma once

template <class Element>
class ListNode {
public:
	Element element;
	ListNode* next;

	ListNode(Element element) : element(element), next(nullptr) {}
};