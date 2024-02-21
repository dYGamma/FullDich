#pragma once
#include "Circle.h"

Circle::Circle() : x0(0), y0(0), r0(1) {}

Circle::Circle(double x0, double y0, double r0)
{
	this->x0 = x0;
	this->y0 = y0;
	this->r0 = r0;
}

Circle::Circle(const Circle& c)
{
	this->x0 = c.x0;
	this->y0 = c.y0;
	this->r0 = c.r0;
}

Circle::~Circle() {}


double Circle::getX0() { return x0; };
double Circle::getY0() { return y0; };
double Circle::getR0() { return r0; };

void Circle::IsPointInside(double x, double y) // Метод для проверки принадлежности точки (x, y) кругу
{
	if (pow(x - x0, 2) + pow(y - y0, 2) <= pow(r0, 2))
		cout << "Точка принадлежит кругу!" << endl;
	else
		cout << "Точка не принадлежит кругу!" << endl;
}