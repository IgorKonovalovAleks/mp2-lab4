#include "Expression.h"
#include <gtest.h>

TEST(Expression, throws_when_not_even_amount_of_brackets)
{
	ASSERT_ANY_THROW(Expression e("((1 + 4)"));
}

TEST(Expression, throws_when_order_of_brackets_is_incorrect)
{
	ASSERT_ANY_THROW(Expression e(")(1 + 4()"));
}

TEST(Expression, throws_when_starts_starts_with_binary_operator)
{
	ASSERT_ANY_THROW(Expression e(" +(1 + 4)"));
}

TEST(Expression, throws_when_bracket_starts_with_binary_operator)
{
	ASSERT_ANY_THROW(Expression e("1 +( * 1 + 4)"));
}

TEST(Expression, throws_when_two_dots_in_number)
{
	ASSERT_ANY_THROW(Expression e("12.4.7"));
}

TEST(Expression, throws_when_number_after_number)
{
	ASSERT_ANY_THROW(Expression e("12 .12"));
}

TEST(Expression, throws_when_invalid_letters_are_present)
{
	ASSERT_ANY_THROW(Expression e("f + 3"));
}

TEST(Expression, throws_when_bracket_after_number)
{
	ASSERT_ANY_THROW(Expression e("3 ( 4 + 7)"));
}

TEST(Expression, throws_when_empty_brackets)
{
	ASSERT_ANY_THROW(Expression e("3 / (   )"));
}

TEST(Expression, throws_when_number_after_closing_bracket)
{
	ASSERT_ANY_THROW(Expression e("(1 * 3) 6"));
}

TEST(Expression, throws_when_operator_after_operator)
{
	ASSERT_ANY_THROW(Expression e("1 + - 5"));
}

TEST(Expression, throws_when_closing_bracket_after_operator)
{
	ASSERT_ANY_THROW(Expression e("(4 + 7 -)"));
}

TEST(Expression, throws_when_ends_with_operator)
{
	ASSERT_ANY_THROW(Expression e("5 + 3 -"));
}

TEST(Expression, sum_works_correctly)
{
	Expression e("4 + 3");
	ASSERT_EQ(e.calculate(), 7);
}

TEST(Expression, substract_works_correctly)
{
	Expression e("4 - 3");
	ASSERT_EQ(e.calculate(), 1);
}

TEST(Expression, mulpiplication_works_correctly)
{
	Expression e("4 * 3");
	ASSERT_EQ(e.calculate(), 12);
}

TEST(Expression, division_works_correctly)
{
	Expression e("4 / 3");
	ASSERT_EQ(e.calculate(), 4.0/3.0);
}

TEST(Expression, unary_minus_works_correctly)
{
	Expression e("-3");
	ASSERT_EQ(e.calculate(), -3);
}

TEST(Expression, number_starts_with_dot_is_read_correctly)
{
	Expression e(".9");
	ASSERT_EQ(e.calculate(), .9);
}

TEST(Expression, number_with_dot_in_the_middle_is_read_correctly)
{
	Expression e("12.9");
	ASSERT_EQ(e.calculate(), 12.9);
}

TEST(Expression, number_with_dot_in_the_end_is_read_correctly)
{
	Expression e("9.");
	ASSERT_EQ(e.calculate(), 9);
}
