#include <iostream>
#include <vector>
using namespace std;
vector<double> point_exe() {
	int n;
	double iX;
	vector<double> point;
	cout << "\nВведите количество дополнительных точек: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "] = ";
		cin >> iX;
		point.push_back(iX);
	}
	cout << endl;
	return point;
}
double metod_lagrange(vector<double> x, vector<double> y, double point) {
	double result = 0.0;
	for (int i = 0; i < x.size(); i++) {
		double term = y[i];
		for (int j = 0; j < x.size(); j++) {
			if (i != j) {
				term *= (point - x[j]) / (x[i] - x[j]);
			}
		}
		result += term;
	}
	return result;
}
int main() {
	setlocale(LC_ALL, "ru");
	bool global_break = false;
	int choice = 0;
	while (!global_break) {
		cout << "1 - использовать узловые точки по умолчанию" << endl;
		cout << "2 - ввести узловые точки вручную" << endl;
		cout << "0 - завершить выполнение программы" << endl;
		cout << "\nВаш выбор: ";
		cin >> choice;
		switch (choice) {
		case 0:
			global_break = true;
			cout << "\nВыполнение программы завершено\n";
			break;
		case 1: {
			vector<double> x = { 0.1, 0.8, 1.3, 2.1, 3.1 };
			vector<double> y = { 2.5, 2.9, 2.0, 1.2, 0.6 };
			cout << endl;
			for (int i = 0; i < x.size(); ++i) {
				printf("x[%u] = %5.2f", i, x[i]);
				printf("\ty[%u] = %5.2f\n", i, y[i]);
			}
			vector<double> point = point_exe();
			for (int i = 0; i < point.size(); ++i) {
				double Yinterp;
				Yinterp = metod_lagrange(x, y, point[i]);
				printf("Yintern[%u] = %.3f\n", i, Yinterp);
			}
			cout << endl;
			global_break = true;
			break;
		}
		case 2: {
			int n;
			vector<double> x;
			vector<double> y;
			cout << "/nВведите количество точек интерполяции: ";
			cin >> n;
			for (int i = 0; i < n; ++i) {
				double xi, yi;
				cout << "x[" << i << "] = ";
				cin >> xi;
				cout << "y[" << i << "] = ";
				cin >> yi;
				x.push_back(xi);
				y.push_back(yi);
			}
			vector<double> point = point_exe();
			for (int i = 0; i < point.size(); ++i) {
				double Yinterp;
				Yinterp = metod_lagrange(x, y, point[i]);
				printf("Yintern[%u] = %.3\n", i, Yinterp);
			}
			cout << endl;
			global_break = true;
			break;
		}
		default:
			cout << "\nТакого действия нет. Повторите ввод:\n\n";
			break;
		}
	}
	return 0;
}
