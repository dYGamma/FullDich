#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    double p1 = 0.5;
    double p2 = 0.6;
    double q1 = 1 - p1;
    double q2 = 1 - p2;

    // Расчет вероятностей
    double P0 = q1 * q1 * q2 * q2;
    double P1 = 2 * p1 * q1 * q2 * q2 + 2 * q1 * q1 * p2 * q2;
    double P2 = p1 * p1 * q2 * q2 + q1 * q1 * p2 * p2 + 4 * p1 * q1 * p2 * q2;
    double P3 = 2 * p1 * p1 * p2 * q2 + 2 * p1 * q1 * p2 * p2;
    double P4 = p1 * p1 * p2 * p2;

    // Вывод ряда распределения
    std::cout << "Ряд распределения X:" << std::endl;
    std::cout << "X   |  0  |  1  |  2  |  3  |  4  |" << std::endl;
    std::cout << "P(X) | " << P0 << " | " << P1 << " | " << P2 << " | " << P3 << " | " << P4 << " |" << std::endl;

    // Расчет математического ожидания
    double MX = 0 * P0 + 1 * P1 + 2 * P2 + 3 * P3 + 4 * P4;

    std::cout << "Математическое ожидание M(X) ~= " << MX << std::endl;

    return 0;
}