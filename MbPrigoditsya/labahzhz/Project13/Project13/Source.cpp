#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

//класс угла
class Angle {
protected:
	bool type;
	double degrees;
	double radians;
public:
	Angle();
	Angle(double _degrees);

	void scan();

	void calc_radians();
	void calc_degrees();

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


	void print();

	Angle operator+(Angle& other);
	Angle operator-(Angle& other);

};

Angle::Angle() {
	type = true;
	degrees = 0;
	radians = 0;
}

Angle::Angle(double _degrees) {
	type = true;
	degrees = _degrees;
	rationing();
}

void Angle::calc_radians() {
	double Pi = 3.14159265;
	radians = degrees * Pi / 180;
}

void Angle::scan() {
	cout << "\tВведите меру угла: 0/1: ";
	int _type; cin >> _type;
	type = !_type;
	if (type) {
		cout << "\tВведите угол в градусах: ";
		cin >> degrees;
		calc_radians();
	}
	else {
		cout << "\tВведите угол в радианах: ";
		cin >> radians;
		calc_degrees();
	}
}

void Angle::calc_degrees() {
	double Pi = 3.14159265;
	degrees = radians * 180 / Pi;
}

void Angle::rationing() {
	while (degrees < 0) { degrees += 360; }		
	while (degrees > 360) { degrees -= 360; }	
	calc_radians();								
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




class Triangle : public Angle {
private:
	double a;	
public:
	Triangle();
	Triangle(double _degrees);

	Triangle(double _a, int _degrees);
	void scan();
	void print();

	double get_area();


	double get_a();
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
	set_degrees(_degrees);
}

void Triangle::scan() {
	cout << "\tВведите длину катета: ";
	cin >> a;
	Angle::scan();
}

void Triangle::print() {

	cout << "Катет: " << a << '\n';
	cout << "Угол при катете: " << get_degrees() << '\n';
}

//функция вычисляет площадь
double Triangle::get_area() {
	return a * get_b() / 2;
}

double Triangle::get_a() {
	return a;
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

	int cmd;
	bool input1 = false, input2 = false;
	Angle a1, a2;
	Triangle t1;

	while (true) {
		cout << "\n0- Завершение программы\n";
		cout << "1- Ввести углы\n";
		cout << "2- Информация об углах\n";
		cout << "3- Сумма углов\n";
		cout << "4- Разность углов\n";
		cout << "5- Ввести прямоугольный треугольник\n";
		cout << "6- Информация о треугольнике\n";
		cout << "7- Площадь треугольника\n";
		cout << "8- Стороны треугольника\n";
		cout << "Введите команду: ";
		cin >> cmd; cout << '\n';

		if (cmd == 0) { break; }
		if (cmd == 1) {
			cout << "Ввод первого угла:\n";
			a1.scan();

			cout << "Ввод второго угла:\n";
			a2.scan();

			input1 = true;
		}
		else if (cmd < 5 && !input1) {
			cout << "Нужно сначала ввести углы!\n";
		}
		else if (cmd > 5 && !input2) {
			cout << "Нужно сначала ввести треугольник!\n";
		}
		else
			if (cmd == 2) {
				cout << "Первый угол: "; a1.print(); cout << '\n';
				cout << "Второй угол: "; a2.print(); cout << '\n';
			}
			else
				if (cmd == 3) {
					cout << "Сумма углов: "; (a1 + a2).print(); cout << '\n';
				}
				else
					if (cmd == 4) {
						cout << "Разность углов: "; (a1 - a2).print(); cout << '\n';
					}
					else
						if (cmd == 5) {
							cout << "Ввод треугольника:\n";
							t1.scan();
							input2 = true;
						}
						else
							if (cmd == 6) {
								cout << "Информация о прямоугольном треугольнике:\n";
								t1.print();
							}
							else
								if (cmd == 7) {
									cout << "Площадь треугольника: " << t1.get_area() << "\n";
								}
								else
									if (cmd == 8) {
										cout << "Стороны треугольника:\n\t" << t1.get_a() << "\n\t" << t1.get_b() << "\n\t" << t1.get_c() << "\n";
									}
	}


}