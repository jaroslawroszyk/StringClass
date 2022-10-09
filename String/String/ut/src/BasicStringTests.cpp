#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class BasicStringTests : public ::testing::Test
{
protected:
    BasicStringTests(){};

    ~BasicStringTests() override{};
};
// todo add checking capacity and data

TEST_F(BasicStringTests, CanCreateEmptyString)
{
    String sut;
    int expectedSize = 0;
    EXPECT_EQ(sut.size(), expectedSize);
}

TEST_F(BasicStringTests, CanCreateStringWithOneChar)
{
    String sut{"d"};
    int expectedLength = 1;
    EXPECT_EQ(sut.length(), expectedLength);
}

TEST_F(BasicStringTests, CanCreateStringWithConstCharAssign)
{
    const char* hello{"hello"};
    String sut{hello};
    int expectedSize = 5;
    EXPECT_EQ(sut.size(), expectedSize);
}

TEST_F(BasicStringTests, CanCreateStringAndCopyItFromAnotherString)
{
    String from{"hello"};
    String dest = from;
    int expectedLength = 5;
    EXPECT_EQ(dest.length(), expectedLength);
}

TEST_F(BasicStringTests, CanCreateStringAndCheckIsLengthIsCorrect)
{
    String sut{"hellohellohellohellohellohello"};
    int expectedLength = 30;
    EXPECT_EQ(sut.length(), expectedLength);
}

TEST_F(BasicStringTests, CanCreateStringAndCheckAfterAssignCharArrayIsLengthIsCorrect)
{
    char str[] = "Hello in my test!";
    String sut(str);
    int expectedLength = 17;
    EXPECT_EQ(sut.length(), expectedLength);
}

TEST_F(BasicStringTests, CanCreateStringAndCheckDataUssageIsCorrect)
{
    String sut{"Hii"};
    int expectLen = 3;
    auto val = sut.data();
    EXPECT_EQ(strlen(val), expectLen);
}

TEST_F(BasicStringTests, StringUseMoveCtrAndCheckSize)
{
    String sut{"Hii"};
    String mv = std::move(sut);
    int expectedSize = 3;
    EXPECT_EQ(mv.size(), expectedSize);
}