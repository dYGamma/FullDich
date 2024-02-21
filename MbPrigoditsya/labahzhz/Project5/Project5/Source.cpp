#include "Circle.h"
#include <locale.h>

void inputPoint(double*, double*);
void inputCircle(double*, double*, double*);

int main()
{

	system("chcp 1251");
	system("cls");


	double x, y;

	cout << "���� ��������� �����." << endl;
	inputPoint(&x, &y);
	Circle* c1 = new Circle();
	cout << "���� 1: ";
	cout << "(" << c1->getX0() << ", " <<
		c1->getY0() << "); ������ = " << c1->getR0() << endl;
	c1->IsPointInside(x, y);

	cout << "\n���� ��������� �����." << endl;
	inputPoint(&x, &y);
	double x0, y0, r0;
	inputCircle(&x0, &y0, &r0);

	Circle c2 = Circle(x0, y0, r0);
	cout << "���� 2: ";
	cout << "(" << c2.getX0() << ", " <<
		c2.getY0() << "); ������ = " << c2.getR0() << endl;
	c2.IsPointInside(x, y);

	cout << "\n���� ��������� �����." << endl;
	inputPoint(&x, &y);
	Circle c3 = Circle(c2);
	cout << "\n���� 3 (����� �������): ";
	cout << "(" << c3.getX0() << ", " <<
		c3.getY0() << "); ������ = " << c3.getR0() << endl;
	c3.IsPointInside(x, y);

	system("pause");

	return 0;
}

void inputPoint(double* x, double* y)
{
	cout << "������� x: ";
	cin >> *x;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������ �����! ������� x: ";
		cin >> *x;
	}
	cout << "������� y: ";
	cin >> *y;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������ �����! ������� y: ";
		cin >> *y;
	}
}

void inputCircle(double* x0, double* y0, double* r0)
{
	cout << "\n���� ��������� ������ �����." << endl;
	inputPoint(x0, y0);
	cout << "������� ������: ";
	cin >> *r0;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������ �����! ������� ������: ";
		cin >> *r0;
	}
}