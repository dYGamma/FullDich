#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

class Angle {
protected:
	bool type;		//тип значения угла в данный момент (true- в градусах, false- в радианах)	
	double degrees;	
	double radians;	
public:
	Angle();
	Angle(double _degrees);

	void calc_radians();
	void calc_degrees(); 

	void rationing();
	
	//функции доступа и проверки
	double get_degrees();
	double get_radians();
	bool is_degrees();
	bool is_radians();

	//функции записи
	void set_degrees(double _degrees);
	void set_radians(double _radians);
	void set_type(bool _type);

	void print();

	Angle operator+(Angle& other);

	Angle operator-(Angle& other);


};

Angle::Angle() {
	type = true;
	degrees = 0;
	radians = 0;
}

//конструктор с параметром градусов
Angle::Angle(double _degrees) {
	type = true;
	degrees = _degrees;
	rationing();
}


void Angle::calc_radians() {
	double Pi = 3.14159265;
	radians = degrees * Pi / 180;
}


void Angle::calc_degrees() {
	double Pi = 3.14159265;
	degrees = radians * 180 / Pi;
}

void Angle::rationing() {
	while (degrees < 0) { degrees += 360; }		//ограничиваем угол снизу
	while (degrees > 360) { degrees -= 360; }	//ограничиваем угол сверху
	calc_radians();								//пересчитываем радианы
}

//функции доступа, и проверки
double Angle::get_degrees() {
	return degrees;
}
double Angle::get_radians() {
	return radians;
}
bool Angle::is_degrees() {
	return type;
}
bool Angle::is_radians() {
	return !type;
}

//функции записи
void Angle::set_degrees(double _degrees) {
	degrees = _degrees;
	calc_radians();
}
void Angle::set_radians(double _radians) {
	radians = _radians;
	calc_degrees();
}
void Angle::set_type(bool _type) {
	type = _type;
}

void Angle::print() {
	if (type) {
		cout << degrees << " град.";
	}
	else {
		cout << radians << " рад.";
	}
}

Angle Angle::operator+(Angle& other) {
	Angle newAngle(degrees + other.degrees);
	newAngle.set_type(type); //тип меры у угла суммы будет такой же, как и у левого угла
	newAngle.rationing(); //не забываем привести к нормальному диапазону
	return newAngle;
}

Angle Angle::operator-(Angle& other) {
	Angle newAngle(degrees - other.degrees);
	newAngle.set_type(type);
	newAngle.rationing();
	return newAngle;
}

//класс прямоугольного треугольника
class Triangle : public Angle {
private:
	double a;	//катет
public:

	Triangle();

	Triangle(double _degrees);

	Triangle(double _a, int _degrees); 
	void print();

	double get_area();

	double get_c();

	double get_b();


};

Triangle::Triangle() : Angle(45) {
	a = 1;
}

Triangle::Triangle(double _degrees) : Angle(_degrees) {
	a = 1;
}

Triangle::Triangle(double _a, int _degrees) {
	a = _a;
	set_radians(_degrees);
}

void Triangle::print() {
	cout << '\n';
	cout << "Катет: " << a << '\n';
	cout << "Уголи при катете: " << get_degrees() << '\n';

	cout << "Площадь: " << get_area() << '\n';
}

//площадь
double Triangle::get_area() {
	return a * get_b() / 2;
}

//гипотенуза
double Triangle::get_c() {
	return sqrt(pow(a, 2.0) + pow(get_b(), 2.0));
}

//второй катет
double Triangle::get_b() {
	return tan(get_radians()) * a;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Angle a1(185), a2(175);

	a1.set_type(true);
	a2.set_type(false);

	cout << "\na1: "; a1.print();
	cout << "\na2: "; a2.print();
	cout << "\na1 + a2: "; (a1 + a2).print();
	cout << "\na1 - a2: "; (a1 - a2).print();
	cout << "\n";

	Triangle t1, t2(30), t3(2, 60);

	cout << "\nТреугольник 1:";
	t1.print();

	cout << "\nТреугольник 2:";
	t2.print();

	cout << "\nТреугольник 3:";
	t3.print();


}