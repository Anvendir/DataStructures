#include "gtest\gtest.h"
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