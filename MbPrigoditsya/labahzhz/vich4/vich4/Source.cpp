#include <iostream>
#include <cmath>

double f(double x) {
    return sin(2 * x + 0.5) / (2 + cos(x * x + 1));
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b;
    int n;

    std::cout << "¬ведите параметр a: ";
    std::cin >> a;
    std::cout << "¬ведите параметр b: ";
    std::cin >> b;
    std::cout << "¬ведите количество разбиений n: ";
    std::cin >> n;

    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    double integral = (h / 2) * (f(a) + 2 * sum + f(b));

    std::cout << "«начение интеграла: " << integral << std::endl;
    return 0;
}
