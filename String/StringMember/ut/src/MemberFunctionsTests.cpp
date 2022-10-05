#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringMemberFunctionsTests : public ::testing::Test
{
protected:
    StringMemberFunctionsTests()
    {};

    ~StringMemberFunctionsTests() override
    {};
};

TEST_F(StringMemberFunctionsTests, CanAssignCharactersIntoStringWithCopyOfStrAndCheckCorrectSize)
{
    String sut{"Test"};
    String text{"Expect"};
    sut.assign(text);
    int expectedSize = 6;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringMemberFunctionsTests, CanAssignCharactersIntoStringWithNewWordndCheckCorrectSize)
{
    String sut{"Test"};
    const char* text = "expected";
    sut.assign(text);
    int expectedSize = 8;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringMemberFunctionsTests, CanAssignCharactersIntoStringWithSpecificSizeAndCheckChorrectSize)
{
    String sut{"Test"};
    const char* text{"Expect"};
    sut.assign(text,6);
    int expectedSize = 6;
    EXPECT_EQ(sut.size(),expectedSize);
}

//check that
//TEST_F(StringMemberFunctionsTests, CanAssignIntoEmptyStringFourCharacters)
//{
//    String sut;
//    char text{'a'};
//    sut.assign(4,text);
//    int expectedSize = 4;
//    EXPECT_EQ(sut.size(),expectedSize);
//}

//didn't work properly
//TEST_F(StringMemberFunctionsTests, CanAssignIntoEmptyStringFourCharacte2rs)
//{
//    String sut;
//    String text{"Text"};
//    sut.assign(text,0,sut.length());
//    int expectedSize = 4;
//    EXPECT_EQ(sut.size(),expectedSize);
//}