#include <iostream>

using namespace std;

double f(double x) {
	return 2 * x * x + 2 * x + 5 / 2;
}

void dicotomy(double a, double b) {
	double eps = 0.5, del = 0.2;
	double Lk, x, yk, zk, Fy, Fz, k = 0, ak = a, bk = b, l = 1;
	Lk = bk - ak;

	while (Lk > l) {
		yk = (ak + bk - del) / 2;
		zk = (ak + bk + del) / 2;
		Fy = f(yk);
		Fz = f(zk);
		// cout << yk << " " << zk << endl << Fy << " " << Fz << endl;
		if (Fy <= Fz) {
			//ak = ak;
			bk = zk;
		}
		else {
			ak = yk;
			//bk = bk;
		}
		Lk = bk - ak;
		cout << "Шаг " << k << ") Отрезок: [" << ak << ", " << bk << "] |Lk| = " << Lk << endl;
		k++;
	}
	cout << endl;
	x = (ak + bk) / 2;
	cout << "L: [" << ak << ", " << bk << "]" << endl << "x = " << x << " +- " << Lk / 2 << endl << endl;
}

void half_diviz(double a, double b) {
	double eps = 0.5, del = 0.2;
	double Lk, xk, yk, zk, Fx, Fy, Fz, k = 0, ak = a, bk = b, l = 1;
	Lk = bk - ak;
	while (Lk > l) {
		xk = (ak + bk) / 2;
		Fx = f(xk);
		yk = ak + Lk / 4;
		zk = bk - Lk / 4;
		Fy = f(yk);
		Fz = f(zk);
		//cout << yk << " " << zk << " " << xk << endl << Fy << " " << Fz  << " " << Fx << endl;
		if (Fy < Fx) {
			bk = xk;
			ak = ak;
			xk = yk;
		}
		else {
			if (Fz < Fx) {
				ak = xk;
				bk = bk;
				xk = zk;
			}
			else {
				ak = yk;
				bk = zk;
				xk = xk;
			}
		}
		cout << "Шаг " << k << ") Отрезок: [" << ak << ", " << bk << "] xk = " << xk << endl;
		Lk = bk - ak;
		k++;
	}
	xk = (ak + bk) / 2;
	cout << "L: [" << ak << ", " << bk << "]" << endl << "x = " << xk << " +- " << Lk / 2 << endl << endl;
}

void RP(double a, double b) {
	int N, i, j;
	double* x, * Fx;
	double min, Lk;

	cout << "Количество разбиений: ";
	cin >> N;

	x = new double[N];
	Fx = new double[N];

	for (i = 0; i < N; i++) {
		x[i] = a + i * (b - a) / (N + 1);
		Fx[i] = f(x[i]);
	}

	min = Fx[0];
	j = 0;
	for (i = 1; i < N; i++) {
		if (Fx[i] < min) {
			min = Fx[i];
			j = i;
		}

	}

	a = x[j - 1];
	b = x[j + 1];
	Lk = b - a;

	cout << "L: [" << a << ", " << b << "]" << endl << "x = " << x[j] << " +- " << Lk / 2 << endl << endl;
}

void main() {
	setlocale(0, "ru");
	double a, b;
	int f = 0;

	cout << "Функция: 2x^2 + 2x + 5/2" << endl;
	cout << "eps = 0,5; del = 0,2" << endl;
	cout << "Введите отрезок: " << endl;
	cin >> a >> b;

	cout << "Методы:" << endl << " 1) Дихотомия;" << endl << " 2) Половинное деление;" << endl << " 3) Равномерный поиск." << endl;
	cout << "Выберите метод: ";
	cin >> f;
	while (f != -1) {
		switch (f) {
		case 1:
			dicotomy(a, b);
			break;
		case 2:
			half_diviz(a, b);
		case 3:
			RP(a, b);
		default:
			break;
		}
		cout << "Можно решить другим методом. Для выхода введите -1." << endl << endl;
		cout << "Выберите метод: ";
		cin >> f;
	}
}
