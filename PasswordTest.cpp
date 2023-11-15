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

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password) // Test Single Letter
{
  Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, multiple_letter_password)
{
  Password my_password;
	int actual = my_password.count_leading_characters("abcd");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, mixed_case_single_lower)
{
  Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_single_upper)
{
  Password my_password;
	bool actual = my_password.has_mixed_case("B");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_multiple_lower)
{
  Password my_password;
	bool actual = my_password.has_mixed_case("abc");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_multiple_upper)
{
  Password my_password;
	bool actual = my_password.has_mixed_case("ABC");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, mixed_case_empty_string)
{
  Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false,actual);
}