#pragma once

#include <vector>

class OneWayList
{
public:
	OneWayList();
	virtual ~OneWayList();

	int getListSize() const;
	void addToTail(int p_element);

private:
	std::vector<int> m_elements;
};

