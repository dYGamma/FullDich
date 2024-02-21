#include <iostream>
#include <cmath>
#include <vector>

double f(double x, double a, double b, double c) {
    return pow(x + a, 3) + b * sin(c * x);
}

double f_prime(double x, double a, double b, double c) {
    return 3 * pow(x + a, 2) + b * c * cos(c * x);
}

double newton(double x0, double a, double b, double c, double epsilon, int& iterations) {
    double x1 = x0 - f(x0, a, b, c) / f_prime(x0, a, b, c);
    iterations = 1;
    while (fabs(x1 - x0) >= epsilon) {
        x0 = x1;
        x1 = x0 - f(x0, a, b, c) / f_prime(x0, a, b, c);
        iterations++;
    }
    return x1;
}

int main() {
    double a, b, c, x0, epsilon, lower_bound, upper_bound;
    int num_points;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Enter initial guess x0: ";
    std::cin >> x0;
    std::cout << "Enter epsilon: ";
    std::cin >> epsilon;
    std::cout << "Enter lower bound of interval: ";
    std::cin >> lower_bound;
    std::cout << "Enter upper bound of interval: ";
    std::cin >> upper_bound;
    std::cout << "Enter number of points: ";
    std::cin >> num_points;

    std::vector<double> points(num_points);
    double dx = (upper_bound - lower_bound) / (num_points - 1);
    for (int i = 0; i < num_points; i++) {
        points[i] = lower_bound + i * dx;
    }

    int iterations;
    for (int i = 0; i < num_points; i++) {
        double root = newton(points[i], a, b, c, epsilon, iterations);
        std::cout << "Root for x = " << points[i] << ": " << root << std::endl;
        std::cout << "f(x): " << f(root, a, b, c) << std::endl;
        std::cout << "Iterations: " << iterations << std::endl << std::endl;
    }

    return 0;
}
