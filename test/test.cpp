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

TEST(Expression, throws_when_name_after_number)
{
	ASSERT_ANY_THROW(Expression e("12 asd"));
}

TEST(Expression, throws_when_number_after_name)
{
	ASSERT_ANY_THROW(Expression e("asdashjd .12"));
}

TEST(Expression, throws_when_name_after_name)
{
	ASSERT_ANY_THROW(Expression e("12 .12"));
}

TEST(Expression, throws_when_invalid_letters_are_present)
{
	ASSERT_ANY_THROW(Expression e("./ + 3"));
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
	ASSERT_EQ(7, e.calculate());
}

TEST(Expression, substract_works_correctly)
{
	Expression e("4 - 3");
	ASSERT_EQ(1, e.calculate());
}

TEST(Expression, mulpiplication_works_correctly)
{
	Expression e("4 * 3");
	ASSERT_EQ(12, e.calculate());
}

TEST(Expression, division_works_correctly)
{
	Expression e("4 / 3");
	ASSERT_EQ(4.0 / 3.0, e.calculate());
}

TEST(Expression, unary_minus_works_correctly)
{
	Expression e("-3");
	ASSERT_EQ(-3, e.calculate());
}

TEST(Expression, log_works_correctly)
{
	Expression e("log 3");
	ASSERT_EQ(std::log(3), e.calculate());
}

TEST(Expression, sin_works_correctly)
{
	Expression e("sin(3)");
	ASSERT_EQ(std::sin(3), e.calculate());
}

TEST(Expression, exp_works_correctly)
{
	Expression e("exp 3");
	ASSERT_EQ(std::exp(3), e.calculate());
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

TEST(Expression, name_is_read_correctly)
{
	Expression e("asd + qwe / _");
	EXPECT_EQ(e.calculate(), 5.0);
}

TEST(Expression, expression_is_calculated_correctly) {
	Expression e("2*3-4");
	EXPECT_EQ(2, e.calculate());
}

