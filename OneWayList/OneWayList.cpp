#include "OneWayList.h"

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

int OneWayList::getListSize()
{
	if (!m_head)
		return 0;

	auto l_counter = 0;
	auto l_tmp = m_head;
	
	while (l_tmp)
	{
		l_counter++;
		l_tmp = l_tmp->m_nextElement;
	}
	return l_counter;
}

void OneWayList::addToTail(int p_element)
{
	if (!m_head)
	{
		m_head = new Node();
		m_head->m_element = p_element;
		m_head->m_nextElement = nullptr;
		m_tail = m_head;
	}
	else
	{
		auto l_temp = new Node();
		l_temp->m_element = p_element;
		l_temp->m_nextElement = nullptr;
		
		if (m_head->m_nextElement == nullptr)
		{
			m_head->m_nextElement = l_temp;
			m_tail = l_temp;
		}
		else
		{
			m_tail->m_nextElement = l_temp;
			m_tail = l_temp;
		}
	}
}