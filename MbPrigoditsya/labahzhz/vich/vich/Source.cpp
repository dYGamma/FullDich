#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double a, double b, double c)
{
    return pow(x + a, 3) + b * sin(c * x);
}

double df(double x, double a, double b, double c)
{
    return 3 * pow(x + a, 2) + b * c * cos(c * x);
}

int main()
{
    double a, b, c, epsilon = 2e-4;//a=-3.21 b = -1.45 c = 2.12 epsilon = 2e-4
    double x0, x, dx;
    int k = 0;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Epsilon: " << epsilon << endl;
    cout << "Enter initial guess: ";
    cin >> x0;

    do {
        x = x0 - f(x0, a, b, c) / df(x0, a, b, c);
        dx = fabs(x - x0);
        x0 = x;
        k++;
    } while (dx > epsilon);

    cout << "Solution: " << x << endl;
    cout << "Iterations: " << k << endl;

    return 0;
}