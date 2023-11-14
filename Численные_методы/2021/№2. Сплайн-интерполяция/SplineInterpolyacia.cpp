# include "stdafx.h"
# include <iostream>
# include <vector>
# include <cmath>
# include <fstream>

// Выполнить аппроксимацию заданной табличной функции y(x) на отрезке x∈[xmin; xmax]. 
//7.Сплайн-интерполяция

using namespace std;

void main() {
	//вводим координаты точек
	ifstream input;
	input.open("Data.txt", ios::in);

	int size;
	input >> size;

	float* x = new float[size];
	for (int i = 0; i < size; i++) {
		input >> x[i];
		cout << x[i] << " ";
	}
	cout << endl;

	float* y = new float[size];
	for (int i = 0; i < size; i++) {
		input >> y[i];
		cout << y[i] << " ";
	}
	cout << endl << endl;

	float min = x[0];
	float max = x[size - 1];
	input.close();

	for (int i = 0; i < size; i++)
		cout << x[i] << " ";
	cout << endl;

	for (int i = 0; i < size; i++)
		cout << y[i] << " ";
	cout << endl << endl;

	cout << "size = " << size << " /  min = " << min << " /  max = " << max << endl << endl;

	//начинаем разбиение отрезка x --> xx
	vector<float> xx; // получим сейчас
	vector<float> yy; // решение задачи, которое необх. найти
	float step = 0.01;
	float value = x[0];
	int num = (max - min) / step; // число всех точек

	for (float i = 0; i <= num; i++) {
		xx.push_back(value);
		value += step;
	}
	int size_xx = xx.size();

	// приращение арг. в т. по x и у
	vector<float> dx, dy;
	for (int i = 0; i < size - 1; i++) {
		double temp_dx = x[i + 1] - x[i];
		dx.push_back(temp_dx);
		double temp_dy = y[i + 1] - y[i];
		dy.push_back(temp_dy);
	}

	// инициализируем матрицу H и заполняем её нулями
	float** matrH;
	matrH = new float*[size];
	for (int i = 0; i < size; i++)
		matrH[i] = new float[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrH[i][j] = 0;

	// инициализируем и обнуляем вектор Y 
	float* vecY = new float[size];
	for (int i = 0; i < size; i++)
		vecY[i] = 0;

	// инициализируем и обнуляем вектор M
	float* vecM = new float[size];
	for (int i = 0; i < size; i++)
		vecM[i] = 0;

	cout << "dx: ";
	for (int i = 0; i < size - 1; i++)
		cout << dx[i] << " ";
	cout << endl << endl;

	cout << "dy: ";
	for (int i = 0; i < size - 1; i++)
		cout << dy[i] << " ";
	cout << endl << endl;

	// начинаем нахождение элементов матрицы H и вектора Y по формулам
	matrH[0][0] = 1;
	matrH[size - 1][size - 1] = 1;
	for (int i = 1; i < size - 1; i++) {
		matrH[i][i - 1] = dx[i - 1];
		matrH[i][i] = 2 * (dx[i - 1] + dx[i]);
		matrH[i][i + 1] = dx[i];
		vecY[i] = 3 * (dy[i] / dx[i] - dy[i - 1] / dx[i - 1]);
	}

	// Hm=y ==> (H|y)=(m) (m)-?:
	// методом прогонки
	int N1 = size - 1;
	float yYy = matrH[0][0];
	float* A = new float[size];
	float* B = new float[size];
	A[0] = -matrH[0][1] / yYy;
	B[0] = vecY[0] / yYy;

	// прямой ход
	for (int i = 1; i < N1; i++) {
		yYy = matrH[i][i] + matrH[i][i - 1] * A[i - 1];
		A[i] = -matrH[i][i + 1] / yYy;
		B[i] = (vecY[i] - matrH[i][i - 1] * B[i - 1]) / yYy;
	}

	// обратный ход
	vecM[N1] = (vecY[N1] - matrH[N1][N1 - 1] * B[N1 - 1]) / (matrH[N1][N1] + matrH[N1][N1 - 1] * A[N1 - 1]);
	for (int i = N1 - 1; i >= 0; i--)
		vecM[i] = A[i] * vecM[i + 1] + B[i];
	// завершили метод прогонки.

	cout << "matrH:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << matrH[i][j] << " ";
		cout << endl;
	}
	cout << "\n\tvecY:\t||\tvecM" << endl;
	for (int i = 0; i < size; i++)
		cout << "\t" << vecY[i] << "\t||\t" << vecM[i] << endl;

	// находим коэффициенты сплайн-интерполяции по формулам
	vector<float> ai, bi, ci, di;
	for (int i = 0; i < size - 1; i++) {
		ai.push_back(y[i]);
		di.push_back((vecM[i + 1] - vecM[i]) / (3 * dx[i]));
		bi.push_back(dy[i] / dx[i] - dx[i] * (2 * vecM[i] + vecM[i + 1]) / 3);
		ci.push_back(vecM[i]);
	}

	// подинтервалы
	vector<int> x_, xx_;
	for (int i = 0; i < size; i++) {
		int temp = x[i] / 0.1;
		x_.push_back(temp);
	}

	for (int i = 0; i < size_xx; i++) {
		int temp = xx[i] / 0.1;
		xx_.push_back(temp);
	}

	// в каждом подинтервале x[j] <= x[i] <= x[j+1] ...
	for (int i = 0; i < size_xx; i++) {
		int k = 0;
		for (int j = 0; j < size - 1; j++) {
			if (xx_[i] > x_[j] && xx_[i] <= x_[j + 1]) {
				k = j;
				break;
			}
			else if (xx[i] == x[size - 1])
				k = size - 1;
		}
		// ... создаем уравнение и находим значение интерполирующей функции
		float temp = ai[k] + bi[k] * (xx[i] - x[k]) + vecM[k] * pow((xx[i] - x[k]), 2) + di[k] * pow((xx[i] - x[k]), 3);
		yy.push_back(temp);
	}

	ofstream output;
	output.open("Spline01.txt", ios::out);
	for (int i = 0; i < size_xx; i++)
		output << xx[i] << '\t' << yy[i] << std::endl;
	output.close();
}