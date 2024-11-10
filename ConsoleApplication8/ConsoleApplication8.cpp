#include <iostream>
#include <cmath>

double f(double x) {
    return 2 * sin(x) - atan(x);
}

double bisection(double a, double b, double tol) {
    double c;

    if (f(a) * f(b) >= 0) {
        std::cerr << "Некорректный интервал [a, b]: f(a) * f(b) должно быть < 0" << std::endl;
        return NAN; // Неопределенное значение
    }

    while ((b - a) / 2.0 > tol) {
        c = (a + b) / 2.0; // Находим середину

        if (f(c) == 0.0) // c — корень
            return c;

        if (f(c) * f(a) < 0) // Корень в [a, c]
            b = c;
        else // Корень в [c, b]
            a = c;
    }

    return (a + b) / 2.0; // Возвращаем среднее значение как приближенный корень
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 2.5;
    double b = 2.6;
    double tolerance = 0.001;

    double root = bisection(a, b, tolerance);

    if (!std::isnan(root)) // Проверка, если root является числом
        std::cout << "Корень уравнения: " << root << std::endl;

    return 0;
}