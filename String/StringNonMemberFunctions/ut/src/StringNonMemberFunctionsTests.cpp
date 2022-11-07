#include <gtest/gtest.h>
#include "../include/String.hpp"

using namespace my;

class StringNonMemberFunctionsTests : public ::testing::Test
{
protected:
    StringNonMemberFunctionsTests(){};

    ~StringNonMemberFunctionsTests() override{};
};

TEST_F(StringNonMemberFunctionsTests, checkCorrectBehaviourWhenSwapTwoStrings)
{
    String left{"left"};
    String right{"right"};
    swap(left, right);
    String expected{"right"};
    EXPECT_EQ(left, expected);
}