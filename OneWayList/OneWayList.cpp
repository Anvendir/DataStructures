#include "OneWayList.h"

OneWayList::OneWayList()
{
}

OneWayList::~OneWayList()
{
}

int OneWayList::getListSize() const
{
	return m_elements.size();
}

void OneWayList::addToTail(int p_element)
{
	m_elements.push_back(p_element);
}