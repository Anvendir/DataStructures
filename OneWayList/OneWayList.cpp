#include "OneWayList.h"
#include <iostream>

OneWayList::Node::Node()
	: m_element(0), m_nextElement(nullptr)
{

}

OneWayList::Node::Node(int p_element, Node* p_nextElement)
	: m_element(p_element), m_nextElement(p_nextElement)
{

}

OneWayList::OneWayList()
	: m_head(nullptr), m_tail(nullptr)
{
}

OneWayList::~OneWayList()
{
}

void OneWayList::printList() const
{
	for (auto l_tmp = m_head; l_tmp; l_tmp = l_tmp->m_nextElement)
	{
		std::cout << l_tmp->m_element;
		if (l_tmp->m_nextElement)
			std::cout << ", ";
	}
}

int OneWayList::getListSize()
{
	if (!m_head)
		return 0;

	auto l_counter = 0;
	for (auto l_tmp = m_head; l_tmp; l_tmp = l_tmp->m_nextElement)
		l_counter++;

	return l_counter;
}

void OneWayList::addToTail(int p_element)
{
	auto l_temp = new Node();
	l_temp->m_element = p_element;
	l_temp->m_nextElement = nullptr;

	if (!m_head)
		m_head = l_temp;
	else if (!m_head->m_nextElement)
		m_head->m_nextElement = l_temp;
	else
		m_tail->m_nextElement = l_temp;

	m_tail = l_temp;
}

void OneWayList::addToHead(int p_element)
{
	auto l_temp = new Node();
	l_temp->m_element = p_element;
	
	if (!m_head)
	{
		m_head = m_tail = l_temp;
		l_temp->m_nextElement = nullptr;
	}
	else
	{
		l_temp->m_nextElement = m_head;
		m_head = l_temp;
	}
}

int OneWayList::getElementFromTail()
{
	auto l_elementFromTail = m_tail->m_element;

	for (auto l_element = m_head; l_element; l_element = l_element->m_nextElement)
	{
		if (l_element->m_nextElement == m_tail)
		{
			m_tail = l_element;
			m_tail->m_nextElement = nullptr;
			break;
		}
	}
	return l_elementFromTail;
}

int OneWayList::getElementFromHead()
{
	auto l_headElement = m_head->m_element;
	m_head = m_head->m_nextElement;
	return l_headElement;
}

int OneWayList::getElement(int p_elementIndex)
{
	if (p_elementIndex >= getListSize())
		return getElementFromTail();

	if (p_elementIndex == 0)
		return getElementFromHead();

	auto* l_temp = m_head;
	for (auto l_counter = 0; l_counter < p_elementIndex; l_temp = l_temp->m_nextElement, l_counter++);

	auto l_requesteElement = l_temp->m_element;
	auto l_nextElement = l_temp->m_nextElement;

	l_temp = m_head;
	for (auto l_counter = 0; l_counter < p_elementIndex-1; l_temp = l_temp->m_nextElement, l_counter++);
	l_temp->m_nextElement = l_nextElement;

	return l_requesteElement;
}