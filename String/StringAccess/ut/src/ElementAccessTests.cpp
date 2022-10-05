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

TEST_F(StringElementAccessTests, CanCreateStringAndCheckDataUssageIsCorrect)
{
    String sut{"Hii"};
    int expectLen = 3;
    auto val = sut.data();
    EXPECT_EQ(strlen(val), expectLen);
}