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

	cout << "������� ����������" << endl;
	double a, b, eps = 0.00001;
	cin >> a >> b;

	double i = b - h;
	while (i >= a) {

		// ������� ������ ������
		double x = i;
		// ������ ����������� �������� �����
		double nextX = x - (f(x) * h) / (f(x + h) - f(x));
		// ����������, ���� �� ��������� ������ �����������
		while (abs(x - nextX) > eps) {
			x = nextX;
			nextX = nextX = x - (f(x) * h) / (f(x + h) - f(x));
		}
		bool f = 1;
		// ���������� � ��� �������������
		for (int i = 0; i < Xi.size(); i++) {
			if (abs(x - Xi[i]) < eps) {
				f = 0;
			}
		}
		// ���� ������ ����� �� ���� � �� � ����������, �� ���������
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