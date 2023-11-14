#include "stdafx.h"
#include <iostream>
#include <fstream>
#define DELMIN 1e-15
using namespace std;

int main() {
	setlocale(0, "ru");
	int n = 1, i, j, k = 1, f;
	double** a;
	double* y0, *x0, *lambda, *xk;
	double s = 0, norma, L, l = 0, l1;
	char space;
	// считывание размерности матрицы
	fstream file("file1.txt");

	while (!file.eof()) {
		file.get(space);
		if (space == ' ')
			n++;
		if (space == '\n')
			break;
	}
	cout << "Размерность матрицы: " << n << endl;

	a = new double*[n];
	for (i = 0; i < n; i++)
		a[i] = new double[n];
	file.close();
	// считывание самой матрицы
	file.open("file1.txt");
	cout << "Матрица: " << endl;
	if (file) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				file >> a[i][j];
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	file.close();
	// задаются: у - случайный вектор, х - нулевый вектор
	x0 = new double[n];
	y0 = new double[n];
	for (i = 0; i < n; i++) {
		y0[i] = rand();
		x0[i] = 0;
	}
	// находится норма вектора у
	for (i = 0; i < n; i++)
		s += y0[i] * y0[i];

	norma = sqrt(s);
	// задаётся вектор х0
	for (i = 0; i < n; i++)
		x0[i] = y0[i] / norma;

	lambda = new double[n];
	xk = new double[n];

	do {
		s = 0;
		f = 0;
		L = 0;
		// находится лямбда - собственный. вектор 
		for (i = 0; i < n; i++) {
			lambda[i] = 0;
			for (j = 0; j < n; j++)
				lambda[i] += a[i][j] * x0[j];
		}
		// норма вектора лямбд
		for (i = 0; i < n; i++)
			s += lambda[i] * lambda[i];
		norma = sqrt(s);
		// хз что за вектор хk
		for (i = 0; i < n; i++)
			xk[i] = lambda[i] / norma;
		// если в х0 есть хотяб 1 ненулевой элемент, то собств. знач != 0 
		// L превратится в собств. знач
		for (i = 0; i < n; i++) {
			if (abs(x0[i]) > DELMIN) {
				f++;
				L += lambda[i] / x0[i];
			}
		}

		l1 = l;
		if (f == 0)
			l = 0;
		else
			l = L / f;

		for (i = 0; i < n; i++)
			x0[i] = xk[i];
		k++;

	} while (abs(l - l1) > DELMIN);
	// вывод 
	cout << endl << "Собственный вектор: (";
	for (i = 0; i < n; i++) {
		if (abs(lambda[i]) < DELMIN)
			lambda[i] = 0;
		cout << lambda[i] << ", ";
	}
	cout << ")\n\nСобственное значение:" << l << endl;

}