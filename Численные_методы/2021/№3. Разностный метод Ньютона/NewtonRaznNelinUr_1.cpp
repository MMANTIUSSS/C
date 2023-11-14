#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

double f11(double x) {
	return -x * x;
}

double f12(double y) {
	return y;
}

double f13(double z) {
	return z;
}

double f21(double x) {
	return x * x;
}

double f22(double y) {
	return -y * y * y;
}

double f23(double z) {
	return z * z;
}

double f31(double x) {
	return x * x * x;
}

double f32(double y) {
	return y * y * y;
}

double f33(double z) {
	return -z * z * z * z;
}


double((*func[3][3]))(double x);

void enterFunc() {
	func[0][0] = f11;	func[0][1] = f12;   func[0][2] = f13;
	func[1][0] = f21;	func[1][1] = f22;	func[1][2] = f23;
	func[2][0] = f31;	func[2][1] = f32;	func[2][2] = f33;
}

bool converge(double xk[3], double xkp[3], int n, double eps)
{
	double norm = 0;
	for (int i = 0; i < n; i++) {
		norm = max(abs(xk[i] - xkp[i]), norm);
	}
	return norm > eps;
}

double matrYakob[3][3];

void inversion()
{
	int N = 3;
	double temp;

	double** E = new double* [N];

	for (int i = 0; i < N; i++)
		E[i] = new double[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			E[i][j] = 0.0;

			if (i == j)
				E[i][j] = 1.0;
		}

	for (int k = 0; k < N; k++)
	{
		temp = matrYakob[k][k];

		for (int j = 0; j < N; j++)
		{
			matrYakob[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < N; i++)
		{
			temp = matrYakob[i][k];

			for (int j = 0; j < N; j++)
			{
				matrYakob[i][j] -= matrYakob[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = N - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = matrYakob[i][k];

			for (int j = 0; j < N; j++)
			{
				matrYakob[i][j] -= matrYakob[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrYakob[i][j] = E[i][j];

	for (int i = 0; i < N; i++)
		delete[] E[i];

	delete[] E;
}



void enterYkob(double x[3], double h[3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			matrYakob[i][j] = (func[i][j](x[j] + h[j]) - func[i][j](x[j])) / h[j];

		}
	}

	inversion();

}

int main()
{
	setlocale(LC_ALL, ".1251");

	double eps = 0.00001, x[3], p[3], h[3];
	int n = 3;
	
	enterFunc();

	x[0] = 1;	 x[1] = 1;  x[2] = 1;

	h[0] = .01;	 h[1] = .01;  h[2] = .01;

	do {
		enterYkob(x, h);
		for (int i = 0; i < n; i++)
			p[i] = x[i];
		for (int i = 0; i < n; i++)
		{
			double var = 0;
			for (int j = 0; j < n; j++) {
				var += matrYakob[i][j] * func[i][j](p[j]);
			}

			x[i] = (p[i] - var);
		}

	} while (!converge(x, p, 3, eps));

	cout << "Решение системы:" << endl << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i << " = " << x[i] << "" << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			sum += func[i][j](x[j]);
		}
		cout << "b" << i << " = " << sum << endl;
	}


	return 0;
}



