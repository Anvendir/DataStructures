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
	sut.addToTail(0);
	sut.addToTail(1);
	sut.addToTail(5);
	sut.addToTail(3);
	sut.addToTail(82);

	m_expectedOutput = "0, 1, 5, 3, 82";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, addToTailTestOneElement)
{
	sut.addToTail(34);

	m_expectedOutput = "34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, addToTailTestFiveElements)
{
	sut.addToTail(34);
	sut.addToTail(1092);
	sut.addToTail(22);
	sut.addToTail(2);
	sut.addToTail(2);

	m_expectedOutput = "34, 1092, 22, 2, 2";
	checkIfListContainsExepctedElements();
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

	EXPECT_EQ(sut.getElementFromTail(), 34);

	m_expectedOutput = "0, 1, 15, 58";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getFewElementsFromTail)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElementFromTail(), 34);
	EXPECT_EQ(sut.getElementFromTail(), 58);

	m_expectedOutput = "0, 1, 15";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementFromHead)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElementFromHead(), 0);

	m_expectedOutput = "1, 15, 58, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getFewElementsFromHead)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElementFromHead(), 0);
	EXPECT_EQ(sut.getElementFromHead(), 1);
	EXPECT_EQ(sut.getElementFromHead(), 15);

	m_expectedOutput = "58, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getElementWithinRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElement(3), 58);

	m_expectedOutput = "0, 1, 15, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getTwoElementsWithinRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElement(3), 58);
	EXPECT_EQ(sut.getElement(2), 15);

	m_expectedOutput = "0, 1, 34";
	checkIfListContainsExepctedElements();
}

TEST_F(OneWayListTestSuite, getFewElementsWithinRange)
{
	addFewElementsToList();
	expectListContainsAllAddedElements();

	EXPECT_EQ(sut.getElement(3), 58);
	EXPECT_EQ(sut.getElement(2), 15);
	EXPECT_EQ(sut.getElement(2), 34);

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

