#include <iostream>
#include <string>
#include <iostream>
#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TFormula.h"
#include "C:\Users\KDFX Team\Desktop\hjgjgh\lab3stack\lab3stack\TStack.h"
using namespace std;
int main(int argc, char* argv[])
{
	//���������������� �����
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������ �� ������";
	cout << endl;
	cout << "������� ������: ";
	cin >> n;
	TStack <int> s(n);
	cin >> s;
	s.Pop();
	cout << "���� � ��������� ���������: " << endl;
	cout << s;

	/*string formula;
	cout << "������ � ���������";
	cout << endl;
	cout << "������� �������: ";
	cin >> formula;
	TFormula f(formula);
	f.FormulaConverter();
	cout << f.getPostfixForm();
	cout << f.FormulaCalculator();*/
	return 1;
}