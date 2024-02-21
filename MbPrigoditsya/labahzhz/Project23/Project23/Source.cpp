#include <iostream>

class B
{
private:
	int e;
public:
	B();
	B(const int& a);
	~B()
	{
		std::cout << "Работает деструктор B" << std::endl;
	}
	void setE(const int& e);
	void show_B();
};

B::B()
	: e(int())
{
	std::cout << "Работает конструктор по умолчанию B" << std::endl;
}

B::B(const int& a)
	: e(a)
{
	std::cout << "Работает конструктор B: параметр = " << this->e << std::endl;
}

void B::setE(const int& e)
{
	std::cout << "Работает сеттер B: параметр = " << e << std::endl;
	this->e = e;
}

void B::show_B()
{
	std::cout << "B= " << e << std::endl;
}

class D1 : virtual public B
{
private:
	int e;
public:
	D1(const int& b, const int& d1);
	~D1()
	{
		std::cout << "Работает деструктор D1" << std::endl;
	}
	void show_D1();
};

D1::D1(const int& b, const int& d1)
	: e(d1)
{
	setE(b);
	std::cout << "Работает конструктор D1: параметр = " << this->e << std::endl;
}

void D1::show_D1()
{
	std::cout << "D1= " << e << std::endl;
	show_B();
}

class D2 : virtual protected B
{
private:
	int e;
public:
	D2(const int& b, const int& d2);
	~D2()
	{
		std::cout << "Работает деструктор D2" << std::endl;
	}
	void show_D2();
};

D2::D2(const int& b, const int& d2)
	: B(b), e(d2)
{
	std::cout << "Работает конструктор D2: параметр = " << this->e << std::endl;
}

void D2::show_D2()
{
	std::cout << "D2= " << e << std::endl;
	show_B();
}

class D3 : public D2
{
private:
	int e;
public:
	D3(const int& b, const int& d2, const int& d3);
	~D3()
	{
		std::cout << "Работает деструктор D3" << std::endl;
	}
	void show_D3();
};

D3::D3(const int& b, const int& d2, const int& d3)
	: B(b), D2(b, d2), e(d3)
{
	std::cout << "Работает конструктор D3: параметр = " << this->e << std::endl;
}

void D3::show_D3()
{
	std::cout << "D3= " << e << std::endl;
	show_D2();
}

class D4 : protected D1, private D3
{
private:
	int e;
public:
	D4(const int& b, const int& d1, const int& d2, const int& d3, const int& d4);
	~D4()
	{
		std::cout << "Работает деструктор D4" << std::endl;
	}
	void show_D4();
};

D4::D4(const int& b, const int& d1, const int& d2, const int& d3, const int& d4)
	:D1(b, d1), D3(d1, d2, d3), e(d4)
{
	std::cout << "Работает конструктор D4: параметр = " << this->e << std::endl;
}

void D4::show_D4()
{
	std::cout << "D4= " << e << std::endl;
	show_D1();
	show_D3();
}

int main()
{
	setlocale(LC_ALL, "");
	system("color F0");


	D4 tmp_d4(0, 1, 2, 3, 4);
	std::cout << "D4 tmp_d4(0, 1, 2, 3, 4)" << std::endl;
	std::cout << "Следуя иерархии класса D4:" << std::endl;
	tmp_d4.show_D4();
	std::cout << std::endl;

	return 0;
}