#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

//класс угла
class Angle {
private:
	//поля класса
	bool type;		//тип значения угла в данный момент (true- в градусах, false- в радианах)	
	double degrees;	//значение градусов
	double radians;	//значение радиан
public:
	//конструктор по умолчанию создает угол в 0 градусов
	Angle();

	//конструктор с параметром градусов
	Angle(double _degrees);

	//функция определяет значение радиан по градусам
	void calc_radians();
	//функция определяет значение градусов по радианам
	void calc_degrees();

	//функция нормирует угол (приводит к значению 0-360)
	void rationing();

	//функции доступа, и проверки
	double get_degrees();
	double get_radians();
	bool is_degrees();
	bool is_radians();

	//функции записи
	void set_degrees(double _degrees);
	void set_radians(double _radians);
	void set_type(bool _type);

	//функция вывода в консоль, с учетом типа
	void print();

	//перегрузка оператора сложения
	Angle operator+(Angle& other);
	//перегрузка оператора вычитания
	Angle operator-(Angle& other);


};

//------------------------Реализацния Angle--------------------//
//конструктор по умолчанию создает угол в 0 градусов
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

//функция определяет значение радиан по градусам
void Angle::calc_radians() {
	double Pi = 3.14159265;
	radians = degrees * Pi / 180;
}

//функция определяет значение градусов по радианам
void Angle::calc_degrees() {
	double Pi = 3.14159265;
	degrees = radians * 180 / Pi;
}

//функция нормирует угол (приводит к значению 0-360)
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

//функция вывода в консоль, с учетом типа
void Angle::print() {
	//вывод градусов
	if (type) {
		cout << degrees << " град.";
	}
	else {
		cout << radians << " рад.";
	}
}

//перегрузка оператора сложения
Angle Angle::operator+(Angle& other) {
	Angle newAngle(degrees + other.degrees);
	newAngle.set_type(type); //тип меры у угла суммы будет такой же, как и у левого угла
	newAngle.rationing(); //не забываем привести к нормальному диапазону
	return newAngle;
}
//перегрузка оператора вычитания
Angle Angle::operator-(Angle& other) {
	Angle newAngle(degrees - other.degrees);
	newAngle.set_type(type);
	newAngle.rationing();
	return newAngle;
}

//класс прямоугольного треугольника
class Triangle : Angle {
private:
	double a;	//катет
public:

	//конструктор по умолчанию создает треугольник с катетами единицами и углом 45 градусов
	Triangle();

	//конструктор с одним параметром создает треугольник с катетами единицами и заданным углом в градусах
	Triangle(double _degrees);

	//конструктор с двумя параметрами катетом и углом при этом катете
	Triangle(double _a, int _degrees);
	//функция вывода информации о треугольнике
	void print();

	//функция вычисляет площадь
	double get_area();

	//функция вычисляет гипотенузу
	double get_c();

	//функция вычисляет второй катет
	double get_b();


};

//конструктор по умолчанию создает треугольник с катетами единицами и углом 45 градусов
Triangle::Triangle() : Angle(45) {
	a = 1;
}

//конструктор с одним параметром создает треугольник с катетами единицами и заданным углом в градусах
Triangle::Triangle(double _degrees) : Angle(_degrees) {
	a = 1;
}

//конструктор с двумя параметрами катетом и углом при этом катете
Triangle::Triangle(double _a, int _degrees) {
	a = _a;
	set_degrees(_degrees);
}

//функция вывода информации о треугольнике
void Triangle::print() {
	//выводим стороны
	cout << '\n';
	cout << "Катет: " << a << '\n';
	cout << "Уголи при катете: " << get_degrees() << '\n';

	cout << "Площадь: " << get_area() << '\n';
}

//функция вычисляет площадь
double Triangle::get_area() {
	return a * get_b() / 2;
}

//функция вычисляет гипотенузу
double Triangle::get_c() {
	return sqrt(pow(a, 2.0) + pow(get_b(), 2.0));
}

//функция вычисляет второй катет
double Triangle::get_b() {
	return tan(get_radians()) * a;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//создадим два угла
	Angle a1(405), a2(-180);

	//второму углу поставим меру в радианах
	a2.set_type(false);

	//выведим углы, сумму и разность
	cout << "\na1: "; a1.print();
	cout << "\na2: "; a2.print();
	cout << "\na1 + a2: "; (a1 + a2).print();
	cout << "\na2 - a1: "; (a2 - a1).print();
	cout << "\n";

	//далее создадим три треугольника тремя разными конструкторами
	Triangle t1, t2(30), t3(2, 60);

	//выведем информацию о них
	cout << "\nТреугольник 1:";
	t1.print();

	cout << "\nТреугольник 2:";
	t2.print();

	cout << "\nТреугольник 3:";
	t3.print();


}