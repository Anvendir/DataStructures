#include "gtest\gtest.h"
#include <string>
#include "OneWayList.h"

struct OneWayListTestSuite : public ::testing::Test
{
	void addFewElementsToList()
	{
		sut.addToHead(34);
		sut.addToHead(58);
		sut.addToHead(15);
		sut.addToHead(1);
		sut.addToHead(0);
	}

	void expectListContainsAllAddedElements()
	{
		testing::internal::CaptureStdout();
		sut.printList();

		m_actualOutput = testing::internal::GetCapturedStdout();
		EXPECT_STREQ(m_expectedOutput.c_str(), m_actualOutput.c_str());
	}

	void checkIfListContainsExepctedElements()
	{
		testing::internal::CaptureStdout();
		sut.printList();

		m_actualOutput = testing::internal::GetCapturedStdout();
		EXPECT_STREQ(m_expectedOutput.c_str(), m_actualOutput.c_str());
	}

	OneWayList sut;
	std::string m_expectedOutput = "0, 1, 15, 58, 34";
	std::string m_actualOutput = "";

};

TEST_F(OneWayListTestSuite, getListSizeWillReturnZeroForEmptyList)
{
	EXPECT_EQ(0, sut.getListSize());
}

TEST_F(OneWayListTestSuite, getListSizeWillReturnOneForOneElementList)
{
	sut.addToTail(5);
	EXPECT_EQ(1, sut.getListSize());
}

TEST_F(OneWayListTestSuite, getListSizeWillReturnFourForForElementList)
{
	addFewElementsToList();
	EXPECT_EQ(5, sut.getListSize());
}

TEST_F(OneWayListTestSuite, printListTest)
{
	m_expectedOutput = "0, 1, 5, 3, 82";
	sut.addToTail(0);
	sut.addToTail(1);
	sut.addToTail(5);
	sut.addToTail(3);
	sut.addToTail(82);
	
	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(m_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToTailTestOneElement)
{
	m_expectedOutput = "34";
	sut.addToTail(34);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(m_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToTailTestFiveElements)
{
	m_expectedOutput = "34, 1092, 22, 2, 2";
	sut.addToTail(34);
	sut.addToTail(1092);
	sut.addToTail(22);
	sut.addToTail(2);
	sut.addToTail(2);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(m_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToHeadTestOneElement)
{
	sut.addToHead(34);

	m_expectedOutput = "34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, addToHeadTestTwoElements)
{
	sut.addToHead(34);
	sut.addToHead(58);

	m_expectedOutput = "58, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, addToHeadTestFiveElements)
{
	addFewElementsToList();
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementFromTail)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElementFromTail();
	EXPECT_EQ(l_listElement, 34);

	m_expectedOutput = "0, 1, 15, 58";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getFewElementsFromTail)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElementFromTail();
	EXPECT_EQ(l_listElement, 34);

	l_listElement = sut.getElementFromTail();
	EXPECT_EQ(l_listElement, 58);

	m_expectedOutput = "0, 1, 15";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementFromHead)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 0);

	m_expectedOutput = "1, 15, 58, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getFewElementsFromHead)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 0);
	l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 1);
	l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 15);

	m_expectedOutput = "58, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementWithinRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElement(3);
	EXPECT_EQ(l_listElement, 58);

	m_expectedOutput = "0, 1, 15, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getTwoElementsWithinRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElement(3);
	EXPECT_EQ(l_listElement, 58);
	l_listElement = sut.getElement(2);
	EXPECT_EQ(l_listElement, 15);

	m_expectedOutput = "0, 1, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getFewElementsWithinRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	auto l_listElement = sut.getElement(3);
	EXPECT_EQ(l_listElement, 58);
	l_listElement = sut.getElement(2);
	EXPECT_EQ(l_listElement, 15);
	l_listElement = sut.getElement(2);
	EXPECT_EQ(l_listElement, 34);

	m_expectedOutput = "0, 1";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementOutOfRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElement(10), 34);

	m_expectedOutput = "0, 1, 15, 58";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementForFirstElementRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElement(0), 0);

	m_expectedOutput = "1, 15, 58, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementForLastElementRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElement(4), 34);

	m_expectedOutput = "0, 1, 15, 58";
	checkIfListContainsExepctedElements();
}

