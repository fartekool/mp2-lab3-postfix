#include "tpostfix.h"
#include "tpostfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix p("a+b"));
	ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, cant_create_postfix_with_empty_string)
{
	ASSERT_ANY_THROW(TPostfix p(""));
}

TEST(TPostfix, can_get_infix)
{
	TPostfix a("a+b");
	ASSERT_NO_THROW(a.GetInfix());
}

TEST(TPostfix, method_getinfix_works_correctly)
{
	TPostfix a("a+b");
	TPostfix b("(a + b) * (c - d/e)");
	EXPECT_EQ(a.GetInfix(), "a+b");
	EXPECT_EQ(b.GetInfix(), "(a + b) * (c - d/e)");
}

TEST(TPostfix, can_get_postfix)
{
	TPostfix a("a+b");
	ASSERT_NO_THROW(a.GetPostfix());
}

TEST(TPostfix, method_getpostfix_works_correctly)
{
	TPostfix a("a+b");
	std::vector<std::string> A = { "a", "b", "+" };

	TPostfix b("(a +   b) * (c - d/e)");
	std::vector<std::string> B = { "a", "b", "+", "c", "d", "e", "/", "-", "*"};

	TPostfix c("(aq+ bt) * (  cg -   dv/3)");
	std::vector<std::string> C = { "aq", "bt", "+", "cg", "dv", "3", "/", "-", "*" };


	EXPECT_EQ(a.GetPostfix(), A);
	EXPECT_EQ(b.GetPostfix(), B);
	EXPECT_EQ(c.GetPostfix(), C);
}

TEST(TPostfix, can_calculate_expression)
{
	TPostfix p1("1+2*3+10-78");
	TPostfix p2("(a + b) * (c - 10 / e)");
	double a = 0.1, b = 0, c = 3, e = 2.7;


	EXPECT_EQ(1 + 2 * 3 + 10 - 78, p1.Calculate());
	EXPECT_EQ((a + b) * (c - 10 / e), p2.Calculate({ {"a", a}, {"b", b},  {"c", c}, {"e", e} }));
}

