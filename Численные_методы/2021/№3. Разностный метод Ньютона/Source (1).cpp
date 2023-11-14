#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<double> Xi;

double h = 1;

double f(double x) {
	//return sin(x);
	//return x * x - 2 * x + 1;
	return sqrt(x) - 4;
}

void main() {

	setlocale(LC_ALL, ".1251");

	cout << "Введите промежуток" << endl;
	double a, b, eps = 0.00001;
	cin >> a >> b;

	double i = b - h;
	while (i >= a) {

		// текущий нижний предел
		double x = i;
		// первое приближение искомого корня
		double nextX = x - (f(x) * h) / (f(x + h) - f(x));
		// приближаем, пока не достигнем нужной погрешности
		while (abs(x - nextX) > eps) {
			x = nextX;
			nextX = nextX = x - (f(x) * h) / (f(x + h) - f(x));
		}
		bool f = 1;
		// сравниваем с уже существующими
		for (int i = 0; i < Xi.size(); i++) {
			if (abs(x - Xi[i]) < eps) {
				f = 0;
			}
		}
		// если такого корня не было и он в промежутке, то сохраняем
		if (f && nextX <= b && nextX >= a) {
			Xi.push_back(nextX);
		}
		i -= h;

	}
	
	sort(Xi.begin(), Xi.end());

	for (double x : Xi) {
		cout << "x= " << x << endl;
	}
}