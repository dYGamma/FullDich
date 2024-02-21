#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void input_parameters(vector<double>& abn) {
    while (abn[0] >= abn[1]) {
        cout << "������� �������� �:\n";
        cin >> abn[0];
        cout << "������� �������� b:\n";
        cin >> abn[1];
        if (abn[0] >= abn[1])
            cout << "a ������ ���� ������ b\n";
    }
    while (abn[2] <= 0 || trunc(abn[2]) != abn[2]) {
        cout << "������� ���������� ��������:\n";
        cin >> abn[2];
        if (abn[2] <= 0 || trunc(abn[2]) != abn[2])
            cout << "���������� �������� ������ ���� ����� ������������� ������.\n";
    }
    return;
}

double f(double x) {
    return sin(2 * x + 0.5) / (2 + cos(x * x + 1));
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<double> abn{ 0,0,0 };
    input_parameters(abn);
    double a = abn[0];
    double b = abn[1];
    int n = abn[2];
    double sum = (f(a) + f(b)) / 2;
    double step = (b - a) / n;
    double x = a;
    for (int i = 1; i < n; i++) {
        x += step;
        sum += f(x);
    }
    cout << "���������: \n" << sum * step;
    return 0;
}