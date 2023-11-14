#include <iostream>
#include <fstream>
using namespace std;

int i, j, k, l; // k - строка для преобразования других строк, l - главный элемент в столбце
double A, B; // переменные для вычислений

// сделал 2 флажка: 1й - проверка, что все эл-ты столбца нулевые, либо вырожденная; 2й - проверка нулей в строках

int main() {
	setlocale(LC_ALL, "rus");
	ifstream input("1.txt");  // открытие файла для чтения

	int n;
	double** data;

	input >> n;	
	data = new double* [n];

	// расщиренная матрица
	for (i = 0; i < n; i++) {
		data[i] = new double[n + 1]; 
	}

	// чтение строк и столбцов
	for (i = 0; i < n; i++) {
		for (j = 0; j < (n + 1); j++) {
			input >> data[i][j];	
		}
	}

	// вывод
	cout << "Расширенная матрица системы:\n\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < (n + 1); j++) {
			cout << data[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;


	double* x;
	x = new double[n];

	//Прямой ход метода Гаусса
	bool flag1 = 0;
	for (k = 0; k < n; k++) {
		//Поиск максимального по модулю элемента в столбце ниже главной диагонали в рамках столбца, который рассматриваем
		A = abs(data[k][k]);
		i = k;
		for (l = k + 1; l < n; l++)
			if (abs(data[l][k]) > A) {
				i = l;
				A = abs(data[l][k]);
			}

		//Проверка на равенство нулю
		if (A == 0) {
			flag1 = 1;
			break;
		}

		//  перестановка i-ой строки, содержащей главный элемент k-ой строки
		if (i != k) {
			for (j = k; j < n + 1; j++) {
				B = data[k][j];
				data[k][j] = data[i][j];
				data[i][j] = B;
			}
		}

		//преобразование k-ой строки с помощью масштабирующих множителей
		A = data[k][k];
		data[k][k] = 1;
		for (j = k + 1; j < n + 1; j++)
			data[k][j] = data[k][j] / A;

		//преобразование строк с помощью k-ой строки
		for (i = k + 1; i < n; i++) {
			B = data[i][k];
			data[i][k] = 0;
			if (B != 0)
				for (j = k + 1; j < n + 1; j++)
					data[i][j] = data[i][j] - B * data[k][j];
		}
	}

	bool flag2 = 0;
	for (i = 0; i < n; i++) {
		int c = 0;
		for (j = 0; j < n; j++) {
			if (data[i][j])
				c++;
		}
		if (c == n)
			flag2 = 1;
	}

	if (flag1 != 1 || flag2 != 1) {
		//Обратный ход метода Гаусса
		for (i = n - 1; i >= 0; i--) {
			x[i] = 0;
			A = data[i][n];
			for (j = n - 1; j > i; j--)
				A = A - data[i][j] * x[j];
			x[i] = A;
		}

		//Вывод решения
		cout << "Решение системы:" << endl;
		for (i = 0; i < n; i++) {
			cout << "x" << i + 1 << " = " << x[i] << "\n";
		}
		cout << endl;
	}
	else cout << "Вырожденная матрица системы:\n\n";

	delete[] x;
	delete[] data;

	system("pause");
	return 0;
}