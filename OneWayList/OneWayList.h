#pragma once

#include <vector>

class OneWayList
{
public:
	OneWayList();
	virtual ~OneWayList();

	int getListSize();
	void addToTail(int p_element);

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

