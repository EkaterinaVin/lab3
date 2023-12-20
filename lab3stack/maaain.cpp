#include <iostream>
#include <string>
#include <iostream>
#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TFormula.h"
#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TStack.h"
using namespace std;
int main(int argc, char* argv[])
{
	//пользовательские тесты
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Работа со стеком";
	cout << endl;
	cout << "Введите размер: ";
	cin >> n;
	TStack <int> s(n);
	cin >> s;
	s.Pop();
	cout << "Стэк с удаленным элементом: " << endl;
	cout << s;

	/*string formula;
	cout << "Работа с формулами";
	cout << endl;
	cout << "Введите формулу: ";
	cin >> formula;
	TFormula f(formula);
	f.FormulaConverter();
	cout << f.getPostfixForm();
	cout << f.FormulaCalculator();*/
	return 1;
}