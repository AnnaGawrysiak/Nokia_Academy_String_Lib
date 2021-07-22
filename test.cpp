#include <string>
#include "pch.h"
#include "../Nokia1.4/StringLib.h"
#include "../Nokia1.4/StringLib.cpp"


TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


class StringLibTest : public ::testing::Test
{
protected:
    StringLibTest() {};
    ~StringLibTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};


TEST_F(StringLibTest, ErrorStringCompilation)
{
    auto result = utils::StringLib::errorString(5);
    const char* expected = "Error code: 5";
    ASSERT_STREQ(result, expected);
}

TEST_F(StringLibTest, RemoveNumbersReplaceSpacesWithUndescores)
{
    std::string input = "9 8_8 999";
    std::string expected = "___";
    auto result = utils::StringLib::spacesToUnderscoresRemoveNumbers(input);
    ASSERT_EQ(result, expected);
}

TEST_F(StringLibTest, ReturnEmptyString)
{
    std::string input = "";
    std::string expected = "";
    auto result = utils::StringLib::spacesToUnderscoresRemoveNumbers(input);
    ASSERT_EQ(result, expected);
}

TEST_F(StringLibTest, CompareCapitalAndSmallLetters)
{
    std::string input = "9 8_8Aa J999";
    std::string expected = "__Aa_J";
    auto result = utils::StringLib::spacesToUnderscoresRemoveNumbers(input);
    ASSERT_EQ(result, expected);
}

TEST_F(StringLibTest, OneSpaceTest)
{
    std::string input = " ";
    std::string expected = "_";
    auto result = utils::StringLib::spacesToUnderscoresRemoveNumbers(input);
    ASSERT_EQ(result, expected);
}

TEST_F(StringLibTest, SameStrings)
{
    std::string input1 = "Hello9World_";
    std::string input2 = "Hello9World_";
    auto result = utils::StringLib::sameStrings(input1, input2);

    ASSERT_TRUE(result);
}

TEST_F(StringLibTest, DifferentStrings)
{
    std::string input1 = "Hello9World_";
    std::string input2 = "Hello9World_2";
    auto result = utils::StringLib::sameStrings(input1, input2);

    ASSERT_FALSE(result);
}

TEST_F(StringLibTest, SameStringsCapitalAndSmallLetters)
{
    std::string input1 = "Hello9World_M";
    std::string input2 = "Hello9World_m";
    auto result = utils::StringLib::sameStrings(input1, input2);

    ASSERT_FALSE(result);
}

TEST_F(StringLibTest, SameStringsSpacesOnly)
{
    std::string input1 = " ";
    std::string input2 = "  ";
    auto result = utils::StringLib::sameStrings(input1, input2);

    ASSERT_FALSE(result);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}