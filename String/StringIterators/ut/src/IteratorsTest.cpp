#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringIteratorTest : public ::testing::Test
{
protected:
    StringIteratorTest() {};

    ~StringIteratorTest() override{};

    String sut{"Test"};
};

TEST_F(StringIteratorTest, iteratorBeginShoudlReturnFirstLetter)
{
    auto it = sut.begin();
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, iteratorEndShoudlReturnLastLetter)
{
    auto it = sut.end() - 1;
    char expected = 't';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constIteratorBeginShoudlReturnFirstLetter)
{
    auto it = sut.cbegin();
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constIteratorEndShoudlReturnLastLetter)
{
    auto it = sut.cend() - 1;
    char expected = 't';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, reverseIteratorBeginShoudlReturnLastLetter)
{
    auto it = sut.rbegin();
    char expected = 't';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, reverseIteratorEndShoudlReturnFirstLetter)
{
    auto it = sut.rend() - 1;
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constReverseIteratorBeginShoudlReturnLastLetter)
{
    auto it = sut.crbegin();
    char expected = 't';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constReverseIteratorEndShoudlReturnFirstLetter)
{
    auto it = sut.crend() - 1;
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}