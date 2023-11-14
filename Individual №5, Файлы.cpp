// #include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
/*
int main() {
	int n, i, x, k = 0, max;
	ofstream f ("f.dat");
	cout << "Input n: " << endl;
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Input x: " << endl;
		cin >> x;
		if (i != n - 1)
			f << x << endl;
		else
			f << x;
	}
	f.close();

	cout << "File: ";
	ifstream h;
	h.open("f.dat");

	while (!h.eof()) {
		h >> x;
		cout << x << " ";
	}
	h.close();
	cout << endl;
	h.open("f.dat");
	h >> max;

	while (!h.eof()) {
		h >> x;
		if (x > max)
			max = x;
	}
	h.close();
	h.open("f.dat");
	while (!h.eof()) {
		h >> x;
		if (x == max)
			k++;
	}
	h.close();
	cout << "Max: " << max << endl;
	cout << "n: " << k << endl;
	system("pause");
}
*/

// Дан файл целых чисел. Найти кол-во квадратов не простых чисел среди компонент файла.

int main() {
	int n, i, x, j, k = 0, kl = 0;
	bool found;
	ofstream f("f.txt");	// запись в файл
	cout << "Input n: " << endl;
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Input x: " << endl;
		cin >> x;
		if (i != n - 1)
			f << x << endl;
		else
			f << x;
	}
	f.close();

	cout << "Numbers in the file: ";
	ifstream h;		// чтение из файла

	h.open("f.txt");
	while (!h.eof()) {
		h >> x;
		cout << x << " ";
	}
	h.close();

	cout << endl;

	h.open("f.txt");
	while (!h.eof()) {
		h >> x;
		if (x > 0) {
			found = false;
			for (i = 1; i <= x && found != true; i++) {		// проверка на квадрат числа
				if (i * i == x) {
					found = true;
					k = 0;
					for (j = 1; j <= i; j++)	// проверка на простое число
						if (i % j == 0)
							k++;
					if (k > 2)
						kl++;				   //результат 
				}
			}
		}
	}
	h.close();

	cout << "Result: " << kl << endl;
	system("pause");
}