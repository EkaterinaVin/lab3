#pragma once
#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TStack.h"
#include <iostream>
#include <string>

using namespace std;
const int MaxLength = 255; // максимальный размер входной строки
class TFormula 
{
private:
	string formula; // входная строка
	string PostfixForm; // постфиксная запись
public:
	TFormula()
	{
		formula = "a + b";
	}
	TFormula(string str) {
		formula = str;
	}
	int rangc(char c)
	{
		if (c == '*' || c == '/')
			return 2;
		if (c == '+' || c == '-')
			return 1;
		else
			return 0;
	}
	bool FormulaChecker(string str)
	{
		int f = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				f++;
			if (str[i] == ')') {

				f--;
				if (f < 0)
					throw "wrong brakets";
			}
		}

		if (f == 0)
			return true;
		else
			throw "wrong brakets";
	}
	string getPostfixForm()
	{
		return PostfixForm;
	}
// проверка правильности
	void FormulaConverter()
	{
		TStack<char> stk;
		PostfixForm = "";
		char c;
		if (FormulaChecker(formula) == false)
			throw "no correct";
		for (int i=0; i<formula.size(); i++)
		{
			c = formula[i];

			if (c == ' ') {
				continue;
			}
			if (c >= '0' && c <= '9')
			{
				PostfixForm += c;
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/')
			{
				/*if (postfix == "" || postfix == " ") throw "Отсутствие операндов";*/
				while (!stk.IsEmpty() && stk.TopView() != '(' && rangc(c) <= rangc(stk.TopView()))
				{
					PostfixForm += stk.Pop();
				}
				stk.Push(c);

				PostfixForm += " ";
			}
			else if (c == '(')
			{
				stk.Push(c);
			}
			else if (c == ')')
			{
				while (!stk.IsEmpty() && stk.TopView() != '(')
				{
					PostfixForm += stk.Pop();
				}
				stk.Pop();
			}
			
		}
		while (!stk.IsEmpty())
		{
			PostfixForm += " ";
			PostfixForm += stk.Pop();
		}
		
	}// перевод в постфиксную форму

	double FormulaCalculator()
	{
		TStack<double> op;
		bool f = false;
		char c;

		for (int i = 0; i < PostfixForm.length(); i++)
		{

			if (PostfixForm[i] == ' ') {
				continue;
			}

			if (PostfixForm[i] >= '0' && PostfixForm[i] <= '9')
			{
				op.Push(stod(PostfixForm.substr(i)));
				while (PostfixForm[i + 1] >= 0 && PostfixForm[i + 1] <= 9)
				{
					i++;
				}
			}
			if (PostfixForm[i] == '+' || PostfixForm[i] == '-' || PostfixForm[i] == '*' || PostfixForm[i] == '/')
			{
				double op2 = op.Pop();
				double op1 = op.Pop();

				switch (PostfixForm[i])
				{
				case '+': {
					op.Push(op1 + op2);
					break; }
				case '-': {
					op.Push(op1 - op2);
					break; }
				case '*': {
					op.Push(op1 * op2);
					break; }
				case '/': {
					op.Push(op1 / op2);
					break; }
				}
			}
			f = false;
		}

		return op.TopView();
	}
	
	// вычисление результата
	

    };