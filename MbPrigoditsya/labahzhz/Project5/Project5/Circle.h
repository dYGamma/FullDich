#pragma once
#pragma once
#include <iostream>
using namespace std;

class Circle
{
private:
	double x0, y0, r0;
public:
	Circle();
	Circle(double, double, double);
	Circle(const Circle&);
	~Circle();

	double getX0();
	double getY0();
	double getR0();
	void IsPointInside(double, double); // ћетод дл€ проверки принадлежности точки (x, y) кругу
};