#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringCapacityTest : public ::testing::Test
{
protected:
    StringCapacityTest()
    {};

    ~StringCapacityTest() override
    {};
};

TEST_F(StringCapacityTest, checkEmptyStringIsEmpty)
{
    String sut;
    EXPECT_TRUE(sut.empty());
}

TEST_F(StringCapacityTest, checkLengthOfGivenString)
{
    String sut{"Hello in my test"};
    int expectedLen = 16;
    EXPECT_EQ(sut.length(),expectedLen);
}

TEST_F(StringCapacityTest, checkSizeOfGivenString)
{
    String sut{"Hello we can check size"};
    int expectedSize = 23;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringCapacityTest, checkCapacityOfGivenString)
{
    String sut{"Capacity"};
    int expectedCapacity= 8;
    EXPECT_EQ(sut.capacity(),expectedCapacity);
}

TEST_F(StringCapacityTest, reserveNewCapacityAndCheckTheValue)
{
    String sut{"Capacity"};
    sut.reserve(100);
    int expectedCapacity= 100;
    EXPECT_EQ(sut.capacity(),expectedCapacity);
}

TEST_F(StringCapacityTest, fillStringWithFiveNumbersAndCheckShrinkUnusedCapacity)
{
    String sut;
    String expected;

    for(int i = 0; i <= 100 ; ++ i)
    {
        sut.push_back('3');
        expected.push_back('3');
    }
    EXPECT_EQ(sut, expected);
    EXPECT_EQ(sut.size(), 101);
    EXPECT_EQ(sut.capacity(), 105);

    sut.shrink_to_fit();
    EXPECT_EQ(sut.size(), 101);
    EXPECT_EQ(sut.capacity(), 105);
}
