#include <iostream>
using namespace std;

// ��������� �������
void findel(int* a, int b, int N);// ������� ������ ��������
void addel(int*& a, int el, int pos, int& N);// ������� ���������� ��������
void delel(int*& a, int pos, int& N);// ������� �������� ��������
void print(int* a, int N);// ������� ������ �������
void combSort(int* a, int n, int& move, int& permutation);// ������� ���������� ���������
void different(int* a, int n, int& count);// ������� ���������� ��������� ���������

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int N = 14;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		a[i] = rand() % 20;
	cout << "����������� ������" << endl;
	print(a, N);
	int x = -1, g, h, k, l, mov = 0, comp = 0, countt = 0;
	cout << "����:\n"
		"1 - ����� ������� �� ��� �����������\n"
		"2 - �������� �������\n"
		"3 - ������� �������\n"
		"4 - ����� ���������� ��������� ����� ����� ��������� �������\n"
		"0 - ��� ������\n";
	while (x != 0)
	{
		cout << "��������, ��� ������ �������: "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "������� �������: "; cin >> g;
			findel(a, g, N);
			cout << endl;
			break;
		case 2:
			cout << "������� ����� ����� ���� ������ �������� �������: "; cin >> h;
			cout << "������� �������: "; cin >> k;
			addel(a, k, h, N);
			print(a, N);
			break;
		case 3:
			cout << "������� ������ ��������, ������� ������ �������: "; cin >> l;
			delel(a, l, N);
			print(a, N);
			break;
		case 4:
			combSort(a, N, mov, comp);
			cout << "��������������� ������" << endl;
			print(a, N);
			cout << "���������� ��������� = " << mov << " ���������� ������������ = " << comp << endl;
			different(a, N, countt);
			cout << "���������� ��������� ��������� = " << countt << endl;
			mov = 0, comp = 0, countt = 0;
			break;
		}
		if (x != 0)
		{
			cout << "����:\n"
				"1 - ����� ������� �� ��� �����������\n"
				"2 - �������� ������� � �����\n"
				"3 - ������� �������\n"
				"4 - ����� ���������� ��������� ����� ����� ��������� �������\n"
				"0 - ��� ������\n";
		}
	}

	return 0;
}


void findel(int* a, int b, int N)
{
	bool f = false;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == b)
		{
			f = true;
			cout << "������ �������� " << b << " = " << i << endl;
		}

	}
	if (!f)
		cout << "������ �������� ���" << endl;
}

void addel(int*& a, int el, int pos, int& N)
{
	int* newarr = new int[N + 1];
	int size = 0;
	if (pos > N || pos < 0)
		cout << "�������� ������" << endl;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (i == pos)// ���� ����� ���� �������� �������
				newarr[size++] = el; // ������ ��� ������� �� �������� �������
			newarr[size++] = a[i];
		}

		delete[] a;
		N = size;
		a = newarr;// �������������� ������ � ����������� ����������� �� 1
	}

}

void print(int* a, int N)
{
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
}

void delel(int*& a, int pos, int& N)
{
	int new_size = N;
	bool f = false;
	int posit = a[pos];
	for (int i = 0; i < new_size; i++)
	{
		if (a[i] == posit)
		{
			f = true;
			for (int j = i; j < N; j++)
			{
				a[j] = a[j + 1];
			}
			new_size--;                  // ������ ���, ��� ������� ������� �������, ������ �������������, ��������� ������ �������
			i--;                         // ������������, ���� ����� ��������� ���������, ������ �������������, ����� �����
		}
	}
	N = new_size;
	if (!f)
		cout << "������ ������� ���" << endl;
}



void combSort(int* a, int n, int& move, int& permutation)
{
	float fakt = 1.2473309;
	int step = n - 1;

	while (step >= 1) {
		for (int i = 0; i + step < n; ++i)
		{
			move++;
			if (a[i] > a[i + step])
			{
				swap(a[i], a[i + step]);// ������������ ��������
				permutation++;
			}
		}
		step /= fakt;
	}
}

void different(int* a, int n, int& count)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != a[i + 1])// ���� ���� �������� ����������, �� ����������� count
			count++;
	}
}