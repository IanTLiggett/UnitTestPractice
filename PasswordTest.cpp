/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, long_repeating_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("EEEEEAWEWE@(*#@#@FB)");
	ASSERT_EQ(5, actual);
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, mixed_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("EEaEEEAWEWE@(*#@#@FB)");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, case_sensitive_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("EEeEEEAWEWE@(*#@#@FB)");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, delayed_repeating_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AEEEEEAWEWE@(*#@#@FB)");
	ASSERT_EQ(1, actual);
}


// std::string didn't seem to have any built in way to iterate over visual characters,
// and workarounds / manual implementation would make Password.cpp several times more complicated

// TEST(PasswordTest, multi_byte_chars_password)
// {
// 	Password my_password;
// 	int actual = my_password.count_leading_characters("ĢĢEEEAWEWE@(*#@#@FB)");
// 	ASSERT_EQ(2, actual);
// }

TEST(PasswordTest, has_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aE");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, all_lowercase_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("adwd32f983fhkjvdfndfkv");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, all_uppercase_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("DFKDJFKBKWKBE))");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, all_lowercase_or_special_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("adfwefnjkf@#$@#"":@:#");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, empty_mixed_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, one_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, long_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a332234ferfwre###@!@!2r4f4ADA");
	ASSERT_EQ(true, actual);
}
