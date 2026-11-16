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
TEST(PasswordTest, multi_byte_chars_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ĢĢEEEAWEWE@(*#@#@FB)");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, has_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aE");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, has_no_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ae");
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

