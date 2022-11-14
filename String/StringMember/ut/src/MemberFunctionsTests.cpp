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
    String sut{"Test"};
};

TEST_F(StringMemberFunctionsTests, CanAssignCharactersIntoStringWithCopyOfStrAndCheckCorrectSize)
{
    String text{"Expect"};
    sut.assign(text);
    int expectedSize = 6;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringMemberFunctionsTests, CanAssignCharactersIntoStringWithNewWordndCheckCorrectSize)
{
    const char* text = "expected";
    sut.assign(text);
    int expectedSize = 8;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringMemberFunctionsTests, CanAssignCharactersIntoStringWithSpecificSizeAndCheckChorrectSize)
{
    const char* text{"Expect"};
    sut.assign(text,6);
    int expectedSize = 6;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringMemberFunctionsTests, CanAssignFourCharactersToStringAndCheckCorrectSizeOfString)
{
    String sut{};
    char ch{'j'};
    sut.assign(4,ch);
    int expectedSize = 4;
    EXPECT_EQ(sut.size(),expectedSize);
}

TEST_F(StringMemberFunctionsTests,testSeveralAssignIntoEmptyString)
{
    String emptyStr{};
    emptyStr.assign(4,'=');
    String expected{"===="};
    // String &assign(size_t , char);
    EXPECT_EQ(emptyStr.size(),expected.size());

    const String str("Exemplary");
    // String &assign(const String &);
    emptyStr.assign(str);
    EXPECT_EQ(emptyStr.size(),str.size());

    emptyStr.assign(String("Hello ") + str);
    int expectedSize = 15;
    EXPECT_EQ(emptyStr.size(),expectedSize);

//    String &assign(const char * , std::size_t);
    expectedSize = 7;
    emptyStr.assign("C-style string", expectedSize);
    EXPECT_EQ(emptyStr.size(),7);

    // String &assign(const char *);
    emptyStr.assign("C-style\0string");
    EXPECT_EQ(emptyStr.size(),expectedSize);
}