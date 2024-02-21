#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

class Angle {
protected:

	bool type;
	double degrees;
	double radians;

public:
	Angle() {
		type = true;
		degrees = 0;
		radians = 0;
	}

	Angle(double _degrees) {
		type = true;
		degrees = _degrees;
		rationing();
	}

	void calc_radians() {
		double Pi = 3.14159265;
		radians = degrees * Pi / 180;
	}

	void scan() {
		cout << "\t������� ���� ����: 0/1: ";
		int _type; cin >> _type;
		type = !_type;
		if (type) {
			cout << "\t������� ���� � ��������: ";
			cin >> degrees;
			calc_radians();
		}
		else {
			cout << "\t������� ���� � ��������: ";
			cin >> radians;
			calc_degrees();
		}
	}

	void calc_degrees() {
		double Pi = 3.14159265;
		degrees = radians * 180 / Pi;
	}

	void rationing() {
		while (degrees < 0) { degrees += 360; }		
		while (degrees > 360) { degrees -= 360; }	
		calc_radians();								
	}


	double get_degrees() {
		return degrees;
	}
	double get_radians() {
		return radians;
	}
	bool is_degrees() {
		return type;
	}
	bool is_radians() {
		return !type;
	}


	void set_degrees(double _degrees) {
		degrees = _degrees;
		calc_radians();
	}
	void set_radians(double _radians) {
		radians = _radians;
		calc_degrees();
	}
	void set_type(bool _type) {
		type = _type;
	}


	void print() {
		if (type) {
			cout << degrees << " ����.";
		}
		else {
			cout << radians << " ���.";
		}
	}

	Angle operator+(Angle& other) {
		Angle newAngle(degrees + other.degrees);
		newAngle.set_type(type); //��� ���� � ���� ����� ����� ����� ��, ��� � � ������ ����
		newAngle.rationing(); //�� �������� �������� � ����������� ���������
		return newAngle;
	}

	Angle operator-(Angle& other) {
		Angle newAngle(degrees - other.degrees);
		newAngle.set_type(type);
		newAngle.rationing();
		return newAngle;
	}



};


class Triangle : public Angle {
private:

	double a;

public:

	Triangle() : Angle(45) {
		a = 1;
	}

	Triangle(double _degrees) : Angle(_degrees) {
		a = 1;
	}

	Triangle(double _a, int _degrees) {
		a = _a;
		set_degrees(_degrees);
	}

	void scan() {
		cout << "\t������� ����� ������: ";
		cin >> a;
		Angle::scan();
	}

	void print() {
		cout << "�����: " << a << '\n';
		cout << "���� ��� ������: " << get_degrees() << '\n';
	}
	//�������
	double get_area() {
		return a * get_b() / 2;
	}

	double get_a() {
		return a;
	}

	//����������
	double get_c() {
		return sqrt(pow(a, 2.0) + pow(get_b(), 2.0));
	}

	//������� ��������� ������ �����
	double get_b() {
		return tan(get_radians()) * a;
	}


};


int main()
{
	setlocale(LC_ALL, "Russian");

	int cmd;
	bool input1 = false, input2 = false;
	Angle a1, a2;
	Triangle t1;

	while (true) {
		cout << "\n0- ���������� ���������\n";
		cout << "1- ������ ����\n";
		cout << "2- ���������� �� �����\n";
		cout << "3- ����� �����\n";
		cout << "4- �������� �����\n";
		cout << "5- ������ ������������� �����������\n";
		cout << "6- ���������� � ������������\n";
		cout << "7- ������� ������������\n";
		cout << "8- ������� ������������\n";
		cout << "������� �������: ";
		cin >> cmd; cout << '\n';

		if (cmd == 0) { break; }
		if (cmd == 1) {
			cout << "���� ������� ����:\n";
			a1.scan();

			cout << "���� ������� ����:\n";
			a2.scan();

			input1 = true;
		}
		else if (cmd < 5 && !input1) {
			cout << "����� ������� ������ ����!\n";
		}
		else if (cmd > 5 && !input2) {
			cout << "����� ������� ������ �����������!\n";
		}
		else
			if (cmd == 2) {
				cout << "������ ����: "; a1.print(); cout << '\n';
				cout << "������ ����: "; a2.print(); cout << '\n';
			}
			else
				if (cmd == 3) {
					cout << "����� �����: "; (a1 + a2).print(); cout << '\n';
				}
				else
					if (cmd == 4) {
						cout << "�������� �����: "; (a1 - a2).print(); cout << '\n';
					}
					else
						if (cmd == 5) {
							cout << "���� ������������:\n";
							t1.scan();
							input2 = true;
						}
						else
							if (cmd == 6) {
								cout << "���������� � ������������� ������������:\n";
								t1.print();
							}
							else
								if (cmd == 7) {
									cout << "������� ������������: " << t1.get_area() << "\n";
								}
								else
									if (cmd == 8) {
										cout << "������� ������������:\n\t" << t1.get_a() << "\n\t" << t1.get_b() << "\n\t" << t1.get_c() << "\n";
									}
	}


}