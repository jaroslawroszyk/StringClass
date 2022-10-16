#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringElementAccessTests : public ::testing::Test
{
protected:
    StringElementAccessTests()
    {};

    ~StringElementAccessTests() override
    {};
};

TEST_F(StringElementAccessTests, CheckWhichLetterIsAtTheIndexZero)
{
    String str{"Hello!"};
    EXPECT_EQ(str.at(0),'H');
}

TEST_F(StringElementAccessTests, CheckWhichLetterIsAtTheIndexZeroConstString)
{
    const String str{"Hello!"};
    EXPECT_EQ(str.at(0),'H');
}

TEST_F(StringElementAccessTests,CheckCorrectReplaceTheLetterUnderIndex3)
{
    String str{"Leteer"};
    str.at(3) = 't';
    EXPECT_EQ(str.at(3),'t');
}

TEST_F(StringElementAccessTests,CheckTheArraySubscriptingOperatorAndAddTheMissingLetter)
{
    String sut{"Su "};
    sut[sut.size() - 1] = 't';
    EXPECT_EQ(sut.at(2),'t');
}

TEST_F(StringElementAccessTests,CheckWhichLetterIsInTheFront)
{
    String sut{"Test"};
    char expected = 'T';
    EXPECT_EQ(sut.front(), expected);
}

TEST_F(StringElementAccessTests,CheckWhichLetterIsInTheBack)
{
    String sut{"Tests"};
    char expected = 's';
    EXPECT_EQ(sut.back(),expected);
}

TEST_F(StringElementAccessTests, CanCreateStringAndCheckDataUssageIsCorrect)
{
    String sut{"Hii"};
    int expectLen = 3;
    auto val = sut.data();
    EXPECT_EQ(strlen(val), expectLen);
}

TEST_F(StringElementAccessTests, UssageCStr)
{
    String sut{"Hii"};
    int expectLen = 3;
    auto val = sut.c_str();
    EXPECT_EQ(strlen(val), expectLen);
}

