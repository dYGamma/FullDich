#include <iostream>

class B
{
public:
	B(const int& a) // Конструктор
		: e(a)
	{
		std::cout << "Работает конструктор B: параметр = " << this->e << std::endl;
	}
	~B() {} // Деструктор
	void show_B()
	{
		std::cout << "B= " << e << std::endl;
	}
private:
	int e;
};

class D1 : virtual public B // Виртуальное наследование т.к. класс B будет дважды присутствувать в D4: публичный B
{
public:
	D1(const int& b, const int& d1) // Конструктор
		: B(b), e(d1)
	{
		std::cout << "Работает конструктор D1: параметр = " << this->e << std::endl;
	}
	~D1() {} // Деструктор
	void show_D1()
	{
		std::cout << "D1= " << e << std::endl;
		show_B();
	}
private:
	int e;
};

class D2 : virtual protected B // Виртуальное наследование т.к. класс B будет дважды присутствувать в D4: защищенный B
{
public:
	D2(const int& b, const int& d2) // Конструктор
		: B(b), e(d2)
	{
		std::cout << "Работает конструктор D2: параметр = " << this->e << std::endl;
	}
	~D2() {} // Деструктор
	void show_D2()
	{
		std::cout << "D2= " << e << std::endl;
		show_B();
	}
private:
	int e;
};

class D3 : public D2 // Наследование: публичный D2
{
public:
	D3(const int& b, const int& d2, const int& d3) // Конструктор
		: B(b), D2(b, d2), e(d3)
	{
		std::cout << "Работает конструктор D3: параметр = " << this->e << std::endl;
	}
	~D3() {} // Деструктор
	void show_D3()
	{
		std::cout << "D3= " << e << std::endl;
		show_D2();
	}
private:
	int e;
};


class D4 : protected D1, private D3 // Множественное наследование: защищенный D1, частный D3
{
public:
	D4(const int& b, const int& d1, const int& d2, const int& d3, const int& d4) // Конструктор
		: B(b), D1(b, d1), D3(d1, d2, d3), e(d4)
	{
		std::cout << "Работает конструктор D4: параметр = " << this->e << std::endl;
	}
	~D4() {} // Деструктор
	void show_D4()
	{
		std::cout << "D4= " << e << std::endl;
		show_D1();
		show_D3();
	}
private:
	int e;
};


int main()
{
	setlocale(LC_ALL, "");

	D1 tmp_d1(0, 1);
	std::cout << "D1 tmp_d1(0, 1)" << std::endl;
	std::cout << "Следуя иерархии класса D1:" << std::endl;
	tmp_d1.show_D1();
	std::cout << std::endl;

	D2 tmp_d2(0, 2);
	std::cout << "D2 tmp_d2(0, 2)" << std::endl;
	std::cout << "Следуя иерархии класса D2:" << std::endl;
	tmp_d2.show_D2();
	std::cout << std::endl;

	D3 tmp_d3(0, 2, 3);
	std::cout << "D3 tmp_d3(0, 2, 3)" << std::endl;
	std::cout << "Следуя иерархии класса D3:" << std::endl;
	tmp_d3.show_D3();
	std::cout << std::endl;

	D4 tmp_d4(0, 1, 2, 3, 4);
	std::cout << "D4 tmp_d4(0, 1, 2, 3, 4)" << std::endl;
	std::cout << "Следуя иерархии класса D4:" << std::endl;
	tmp_d4.show_D4();
	std::cout << std::endl;

	return 0;
}