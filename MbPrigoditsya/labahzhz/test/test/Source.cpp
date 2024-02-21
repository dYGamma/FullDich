#include <iostream>

class B
{
public:
	B(const int& a) // �����������
		: e(a)
	{
		std::cout << "�������� ����������� B: �������� = " << this->e << std::endl;
	}
	~B() {} // ����������
	void show_B()
	{
		std::cout << "B= " << e << std::endl;
	}
private:
	int e;
};

class D1 : virtual public B // ����������� ������������ �.�. ����� B ����� ������ �������������� � D4: ��������� B
{
public:
	D1(const int& b, const int& d1) // �����������
		: B(b), e(d1)
	{
		std::cout << "�������� ����������� D1: �������� = " << this->e << std::endl;
	}
	~D1() {} // ����������
	void show_D1()
	{
		std::cout << "D1= " << e << std::endl;
		show_B();
	}
private:
	int e;
};

class D2 : virtual protected B // ����������� ������������ �.�. ����� B ����� ������ �������������� � D4: ���������� B
{
public:
	D2(const int& b, const int& d2) // �����������
		: B(b), e(d2)
	{
		std::cout << "�������� ����������� D2: �������� = " << this->e << std::endl;
	}
	~D2() {} // ����������
	void show_D2()
	{
		std::cout << "D2= " << e << std::endl;
		show_B();
	}
private:
	int e;
};

class D3 : public D2 // ������������: ��������� D2
{
public:
	D3(const int& b, const int& d2, const int& d3) // �����������
		: B(b), D2(b, d2), e(d3)
	{
		std::cout << "�������� ����������� D3: �������� = " << this->e << std::endl;
	}
	~D3() {} // ����������
	void show_D3()
	{
		std::cout << "D3= " << e << std::endl;
		show_D2();
	}
private:
	int e;
};


class D4 : protected D1, private D3 // ������������� ������������: ���������� D1, ������� D3
{
public:
	D4(const int& b, const int& d1, const int& d2, const int& d3, const int& d4) // �����������
		: B(b), D1(b, d1), D3(d1, d2, d3), e(d4)
	{
		std::cout << "�������� ����������� D4: �������� = " << this->e << std::endl;
	}
	~D4() {} // ����������
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
	std::cout << "������ �������� ������ D1:" << std::endl;
	tmp_d1.show_D1();
	std::cout << std::endl;

	D2 tmp_d2(0, 2);
	std::cout << "D2 tmp_d2(0, 2)" << std::endl;
	std::cout << "������ �������� ������ D2:" << std::endl;
	tmp_d2.show_D2();
	std::cout << std::endl;

	D3 tmp_d3(0, 2, 3);
	std::cout << "D3 tmp_d3(0, 2, 3)" << std::endl;
	std::cout << "������ �������� ������ D3:" << std::endl;
	tmp_d3.show_D3();
	std::cout << std::endl;

	D4 tmp_d4(0, 1, 2, 3, 4);
	std::cout << "D4 tmp_d4(0, 1, 2, 3, 4)" << std::endl;
	std::cout << "������ �������� ������ D4:" << std::endl;
	tmp_d4.show_D4();
	std::cout << std::endl;

	return 0;
}