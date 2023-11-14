#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	//return sin(x);
	//return sqrt(x);
	return x * x - 2 * x + 1;
}

double LeftRect(double a, double b, int n) {
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 0; i <= n - 1; i++)
		sum += h * f(a + i * h);
	return sum;
}

double RightRect(double a, double b, int n) {
	double h = (b - a) / n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++)
		sum += h * f(a + i * h);
	return sum;
}

double MiddleRect(double a, double b, int n) {
	double h = (b - a) / n;
	a += h / 2;
	double sum = 0.0;
	for (int i = 0; i <= n - 1; i++)
		sum += h * f(a + i * h);
	return sum;
}

void main() {
	setlocale(LC_ALL, ".1251");
	double a, b;
	int n;
	cout << "Введите промежуток интегрирования: ";
	cin >> a >> b;
	cout << "Количество интервалов разбиения: ";
	cin >> n;
	cout << "Левые прямоугольники: " << LeftRect(a, b, n) << endl;
	cout << "Правые прямоугольники: " << RightRect(a, b, n) << endl;
	cout << "Средние прямоугольники: " << MiddleRect(a, b, n) << endl;
}