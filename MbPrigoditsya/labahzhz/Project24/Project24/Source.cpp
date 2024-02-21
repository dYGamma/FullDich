#include <iostream>
using namespace std;

// Объявляем функции
void findel(int* a, int b, int N);// Функция поиска элемента
void addel(int*& a, int el, int pos, int& N);// Функция добавления элемента
void delel(int*& a, int pos, int& N);// Функция удаления элемента
void print(int* a, int N);// Функция вывода массива
void combSort(int* a, int n, int& move, int& permutation);// Функция сортировка расчёской
void different(int* a, int n, int& count);// Функция вычисления различных элементов

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int N = 14;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		a[i] = rand() % 20;
	cout << "Изначальный массив" << endl;
	print(a, N);
	int x = -1, g, h, k, l, mov = 0, comp = 0, countt = 0;
	cout << "Меню:\n"
		"1 - Найти элемент по его содержимому\n"
		"2 - Добавить элемент\n"
		"3 - Удалить элемент\n"
		"4 - Найти количество различных чисел среди элементов массива\n"
		"0 - Для выхода\n";
	while (x != 0)
	{
		cout << "Выберите, что хотите сделать: "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Введите элемент: "; cin >> g;
			findel(a, g, N);
			cout << endl;
			break;
		case 2:
			cout << "Введите номер места куда хотите вставить элемент: "; cin >> h;
			cout << "Введите элемент: "; cin >> k;
			addel(a, k, h, N);
			print(a, N);
			break;
		case 3:
			cout << "Введите индекс элемента, который хотите удалить: "; cin >> l;
			delel(a, l, N);
			print(a, N);
			break;
		case 4:
			combSort(a, N, mov, comp);
			cout << "Отсортированный массив" << endl;
			print(a, N);
			cout << "Количество сравнений = " << mov << " количество перестановок = " << comp << endl;
			different(a, N, countt);
			cout << "Количество различных элементов = " << countt << endl;
			mov = 0, comp = 0, countt = 0;
			break;
		}
		if (x != 0)
		{
			cout << "Меню:\n"
				"1 - Найти элемент по его содержимому\n"
				"2 - Добавить элемент в конец\n"
				"3 - Удалить элемент\n"
				"4 - Найти количество различных чисел среди элементов массива\n"
				"0 - Для выхода\n";
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
			cout << "Индекс элемента " << b << " = " << i << endl;
		}

	}
	if (!f)
		cout << "Такого элемента нет" << endl;
}

void addel(int*& a, int el, int pos, int& N)
{
	int* newarr = new int[N + 1];
	int size = 0;
	if (pos > N || pos < 0)
		cout << "Неверный индекс" << endl;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (i == pos)// Если нашли куда вставить элемент
				newarr[size++] = el; // Ставим наш элемент на заданную позицию
			newarr[size++] = a[i];
		}

		delete[] a;
		N = size;
		a = newarr;// Перезаписываем массив и увеличиваем размерность на 1
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
			new_size--;                  // Каждый раз, как находит элемент массива, равный максимальному, уменьшает размер массива
			i--;                         // Перепроверка, если вдруг несколько элементов, равных максимальному, стоят рядом
		}
	}
	N = new_size;
	if (!f)
		cout << "Такого индекса нет" << endl;
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
				swap(a[i], a[i + step]);// Переставляем элементы
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
		if (a[i] != a[i + 1])// Если наши элементы отличаются, то увеличиваем count
			count++;
	}
}