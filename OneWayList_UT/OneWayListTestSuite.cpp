#include "gtest\gtest.h"
#include <string>
#include "OneWayList.h"

struct OneWayListTestSuite : public ::testing::Test
{
	OneWayList sut;
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
	sut.addToTail(1);
	sut.addToTail(5);
	sut.addToTail(3);
	sut.addToTail(82);
	EXPECT_EQ(4, sut.getListSize());
}

TEST_F(OneWayListTestSuite, printListTest)
{
	std::string l_expectedOutput = "1, 5, 3, 82";
	sut.addToTail(1);
	sut.addToTail(5);
	sut.addToTail(3);
	sut.addToTail(82);
	
	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToTailTestOneElement)
{
	std::string l_expectedOutput = "34";
	sut.addToTail(34);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToTailTestFiveElements)
{
	std::string l_expectedOutput = "34, 1092, 22, 2, 2";
	sut.addToTail(34);
	sut.addToTail(1092);
	sut.addToTail(22);
	sut.addToTail(2);
	sut.addToTail(2);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToHeadTestOneElement)
{
	std::string l_expectedOutput = "34";
	sut.addToHead(34);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToHeadTestTwoElements)
{
	std::string l_expectedOutput = "58, 34";
	sut.addToHead(34);
	sut.addToHead(58);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, addToHeadTestFiveElements)
{
	std::string l_expectedOutput = "0, 1, 15, 58, 34";
	sut.addToHead(34);
	sut.addToHead(58);
	sut.addToHead(15);
	sut.addToHead(1);
	sut.addToHead(0);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, getElementFromTail)
{
	std::string l_expectedOutput = "0, 1, 15, 58, 34";
	sut.addToHead(34);
	sut.addToHead(58);
	sut.addToHead(15);
	sut.addToHead(1);
	sut.addToHead(0);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());

	auto l_listElement = sut.getElementFromTail();
	EXPECT_EQ(l_listElement, 34);

	testing::internal::CaptureStdout();
	sut.printList();

	l_expectedOutput = "0, 1, 15, 58";
	l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, getFewElementsFromTail)
{
	std::string l_expectedOutput = "0, 1, 15, 58, 34";
	sut.addToHead(34);
	sut.addToHead(58);
	sut.addToHead(15);
	sut.addToHead(1);
	sut.addToHead(0);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());

	auto l_listElement = sut.getElementFromTail();
	EXPECT_EQ(l_listElement, 34);

	l_listElement = sut.getElementFromTail();
	EXPECT_EQ(l_listElement, 58);

	testing::internal::CaptureStdout();
	sut.printList();

	l_expectedOutput = "0, 1, 15";
	l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, getElementFromHead)
{
	std::string l_expectedOutput = "0, 1, 15, 58, 34";
	sut.addToHead(34);
	sut.addToHead(58);
	sut.addToHead(15);
	sut.addToHead(1);
	sut.addToHead(0);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());

	auto l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 0);

	testing::internal::CaptureStdout();
	sut.printList();

	l_expectedOutput = "1, 15, 58, 34";
	l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}

TEST_F(OneWayListTestSuite, getFewElementsFromHead)
{
	std::string l_expectedOutput = "0, 1, 15, 58, 34";
	sut.addToHead(34);
	sut.addToHead(58);
	sut.addToHead(15);
	sut.addToHead(1);
	sut.addToHead(0);

	testing::internal::CaptureStdout();
	sut.printList();

	std::string l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());

	auto l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 0);
	l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 1);
	l_listElement = sut.getElementFromHead();
	EXPECT_EQ(l_listElement, 15);

	testing::internal::CaptureStdout();
	sut.printList();

	l_expectedOutput = "58, 34";
	l_actualOutput = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(l_expectedOutput.c_str(), l_actualOutput.c_str());
}