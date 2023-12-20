//#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TFormula.h"
//bool TFormula::FormulaChecker(string str)
//{
//	int f = 0;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == '(')
//			f++;
//		if (str[i] == ')') {
//
//			f--;
//			if (f < 0)
//				throw "wrong brakets";
//		}
//	}
//
//	if (f == 0)
//		return true;
//	else
//		throw "wrong brakets";
//}// проверка правильности
//
//void TFormula::FormulaConverter()
//{
//	TStack<char> stk;
//	PostfixForm = "";
//	if (FormulaChecker(formula) == false)
//		throw "no correct";
//	for (char c : formula)
//	{
//		if (c == ' ') {
//			continue;
//		}
//		if (c >= 0 && c <= 9)
//		{
//			PostfixForm += c;
//		}
//		else if (c == '+' || c == '-' || c == '*' || c == '/')
//		{
//			/*if (postfix == "" || postfix == " ") throw "Отсутствие операндов";*/
//			while (!stk.IsEmpty() && stk.TopView() != '(' && rangc(c) <= rangc(stk.TopView()))
//			{
//				PostfixForm += stk.Pop();
//			}
//			stk.Push(c);
//			PostfixForm += " ";
//		}
//		else if (c == '(')
//		{
//			stk.Push(c);
//		}
//		else if (c == ')')
//		{
//			while (!stk.IsEmpty() && stk.TopView() != '(')
//			{
//				PostfixForm += stk.Pop();
//			}
//			stk.Pop();
//		}
//	}
//}// перевод в постфиксную форму
//
//	double TFormula::FormulaCalculator()
//	{
//		TStack<double> op;
//		bool f = false;
//
//		for (int i = 0; i < PostfixForm.length(); i++)
//		{
//
//			if (PostfixForm[i] == ' ') {
//				continue;
//			}
//
//			if (PostfixForm[i] >= 0 && PostfixForm[i] <= 9)
//			{
//				op.Push(stod(PostfixForm.substr(i)));//подумай как это нормально представить(считвать не однозначые числа)
//				while (PostfixForm[i + 1] >= 0 && PostfixForm[i + 1] <= 9)
//				{
//					i++;
//				}
//			}
//			if (PostfixForm[i] == '+' || PostfixForm[i] == '-' || PostfixForm[i] == '*' || PostfixForm[i] == '/')
//			{
//				double op2 = op.Pop();
//				double op1 = op.Pop();
//
//				switch (PostfixForm[i])
//				{
//				case '+': {
//					op.Push(op1 + op2);
//					break; }
//				case '-': {
//					op.Push(op1 - op2);
//					break; }
//				case '*': {
//					op.Push(op1 * op2);
//					break; }
//				case '/': {
//					op.Push(op1 / op2);
//					break; }
//				}
//			}
//			f = false;
//		}
//
//		return op.TopView();
//	}// вычисление результата
//
