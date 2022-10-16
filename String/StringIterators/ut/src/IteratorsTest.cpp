#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringIteratorTest : public ::testing::Test
{
protected:
    StringIteratorTest() {};

    ~StringIteratorTest() override{};
};

TEST_F(StringIteratorTest, iteratorBeginShoudlReturnFirstLetter)
{
    String sut{"Test"};
    auto it = sut.begin();
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, iteratorEndShoudlReturnLastLetter)
{
    String sut{"Tests"};
    auto it = sut.end() - 1;
    char expected = 's';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constIteratorBeginShoudlReturnFirstLetter)
{
    const String sut{"Test"};
    auto it = sut.cbegin();
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constIteratorEndShoudlReturnLastLetter)
{
    const String sut{"Test"};
    auto it = sut.cend() - 1;
    char expected = 't';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, reverseIteratorBeginShoudlReturnLastLetter)
{
    const String sut{"Tests"};
    auto it = sut.rbegin();
    char expected = 's';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, reverseIteratorEndShoudlReturnFirstLetter)
{
    const String sut{"Test"};
    auto it = sut.rend() - 1;
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constReverseIteratorBeginShoudlReturnLastLetter)
{
    const String sut{"Tests"};
    auto it = sut.crbegin();
    char expected = 's';
    EXPECT_EQ(*it, expected);
}

TEST_F(StringIteratorTest, constReverseIteratorEndShoudlReturnFirstLetter)
{
    const String sut{"Test"};
    auto it = sut.crend() - 1;
    char expected = 'T';
    EXPECT_EQ(*it, expected);
}