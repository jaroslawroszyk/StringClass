#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringOperationsTest : public ::testing::Test
{
protected:
    StringOperationsTest(){};

    ~StringOperationsTest() override{};
};

TEST_F(StringOperationsTest, removeAllCharactersFromTheStrng)
{
    String sut{"Test"};
    EXPECT_EQ(sut.size(), 4);
    sut.clear();
    EXPECT_EQ(sut.size(), 0);
}

TEST_F(StringOperationsTest, removesSpecifiedCharacterFromTheString)
{
    String sut{"Test a erase"};
    sut.erase(5, 2);
    String expected{"Test erase"};
    EXPECT_EQ(sut, expected);
}

TEST_F(StringOperationsTest, checkCorrectBehaviourWhenSwapTwoStrings)
{
    String a{"a"};
    String b{"b"};
    char expected = 'b';
    swap(a, b);
    EXPECT_EQ(a.front(), expected);
}

TEST_F(StringOperationsTest, appendTheGivenCharacterChToTheEndOfTheString)
{
    String sut{"test"};
    String expected{"tests"};
    sut.push_back('s');
    EXPECT_EQ(sut, expected);
}

TEST_F(StringOperationsTest, AppendsAdditionalCharactersToTheString)
{
    String sut{"hello"};
    String addToSut{" test"};
    sut += addToSut;
    String expected{"hello test"};
    EXPECT_EQ(sut, expected);
}

TEST_F(StringOperationsTest, compareTwoTheSameStringsExpectTheseStringsCompare)
{
    String sut{"hello"};
    int compare = sut.compare(sut);
    EXPECT_EQ(compare, 0);
}

TEST_F(StringOperationsTest, copySubstringToStringAndCheckSizeOfThem)
{
    String sut{"Test"};
    int sizeSut = sut.size();
    char bar[4]{};
    sut.copy(bar, sizeof(bar));
    EXPECT_EQ(sizeof(bar), sizeSut);
}

TEST_F(StringOperationsTest, checkMemberSwap)
{
    String a{"a"};
    String b{"b"};
    char expected = 'b';
    a.swap(b);
    EXPECT_EQ(a.front(), expected);
}

TEST_F(StringOperationsTest, testInsertFunWithPosANdString)
{
    String sut{"xmplr"};
    sut.insert(2, String{"dupa"});

    String expected{"xmdupaplr"};
    EXPECT_EQ(sut, expected);
}

TEST_F(StringOperationsTest, insertCharacterIntoStringUsingConstCharShouldInsertInCorrectPositions)
{
    String sut{"Exmplr"};
    const char* ch = "e";
    sut.insert(2, ch);

    String expected{"Exemplr"};
    EXPECT_EQ(sut, expected);
}

class StringInsertTestException : public ::testing::TestWithParam<std::tuple<int, String>>
{
};

TEST_P(StringInsertTestException, insertTooMuchThanYouCanShouldThrowException)
{
    int pos = std::get<0>(GetParam());
    String str = std::get<1>(GetParam());
    EXPECT_THROW(
        {
            try
            {
                str.assign("xmplr");
                str.insert(pos, str);
            }
            catch (const std::exception& err)
            {
                EXPECT_STREQ("out of range", err.what());
                throw;
            }
        },
        std::out_of_range);
}

INSTANTIATE_TEST_SUITE_P(
    StringInsertTestShouldThrowExceptions,
    StringInsertTestException,
    ::testing::Values(std::make_tuple(6, String{"dupa"}), std::make_tuple(7, static_cast<const char*>("d"))));