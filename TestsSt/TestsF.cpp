#include "..\..\..\lab2\mp2-lab2-matrix\gtest\gtest.h"
#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TFormula.h"

TEST(TFormula, can_create_formula)
{
	ASSERT_NO_THROW(TFormula c);
}

TEST(TFormula, cant_count_with_unequal_brakets)
{
	TFormula f;
	string s("(2+2)))*5)");
	ASSERT_ANY_THROW(f.FormulaChecker(s));
}

TEST(TFormula, can_count_with_equal_brakets)
{
	TFormula f;
	ASSERT_NO_THROW(f.FormulaChecker("(2+2)*5"));
}



TEST(TFormula, right_postfix)
{
	TFormula f("2 + 2");
	f.FormulaConverter();
	string tmp;
	tmp = ("2 2 +");
	EXPECT_EQ(f.getPostfixForm(), tmp);
}




TEST(TFormula, right_answer)
{
	TFormula f("2+2");
	f.FormulaConverter();
	EXPECT_EQ(f.FormulaCalculator(), 4);
}