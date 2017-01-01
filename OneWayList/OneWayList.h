#pragma once

#include <vector>

class Node;

class OneWayList
{
public:
	OneWayList();
	virtual ~OneWayList();

	int getListSize();
	void printList() const;
	void addToTail(int p_element);
	void addToHead(int p_element);
	int getElementFromTail();
	int getElementFromHead();
	int getElement(int p_elementIndex);

private:
	struct Node
	{
		Node();
		Node(int p_element, Node* p_nextElement = nullptr);

		int m_element;
		Node* m_nextElement = nullptr;
	};
	Node* m_head;
	Node* m_tail;
};

