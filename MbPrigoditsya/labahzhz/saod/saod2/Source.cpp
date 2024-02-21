#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

//класс угла
class Angle {
public:
	//конструктор по умолчанию создает угол в 0 градусов
	Angle();
	//конструктор с параметром градусов
	Angle(double _degrees);

	void scan();

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


private:
	//поля класса
	bool type;		//тип значения угла в данный момент (true- в градусах, false- в радианах)	
	double degrees;	//значение градусов
	double radians;	//значение радиан
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
public:
	//конструктор по умолчанию создает треугольник с катетами единицами и углом 45 градусов
	Triangle();

	//конструктор с одним параметром создает треугольник с катетами единицами и заданным углом в градусах
	Triangle(double _degrees);

	//конструктор с двумя параметрами катетом и углом при этом катете
	Triangle(double _a, int _degrees);

	void scan();
	//функция вывода информации о треугольнике
	void print();

	//функция вычисляет площадь
	double get_area();

	//функция возвращает главный катет
	double get_a();
	//функция вычисляет гипотенузу
	double get_c();
	//функция вычисляет второй катет
	double get_b();

private:
	double a;	//катет
};

//------------------------Реализацния Triangle--------------------//

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

void Triangle::scan() {
	cout << "\tВведите длину катета: ";
	cin >> a;
	Angle::scan();
}
//функция вывода информации о треугольнике
void Triangle::print() {
	//выводим стороны
	cout << "Катет: " << a << '\n';
	cout << "Угол при катете: " << get_degrees() << '\n';
}

//функция вычисляет площадь
double Triangle::get_area() {
	return a * get_b() / 2;
}

//функция возвращает главный катет
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