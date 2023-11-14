#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<double> Xi;

double h = 1;


double f(double x) {
	return sin(x);
}

double Newton(double x) {

	double nextX = x - (f(x) * h) / (f(x + h) - f(x));
	while (abs(x - nextX) > 0.00001) {
		x = nextX;
		nextX = nextX = x - (f(x) * h) / (f(x + h) - f(x));
	}

	return nextX;
}

bool checkX(double x) {

	for (int i = 0; i < Xi.size(); i++) {
		if (abs(x - Xi[i]) < 0.0001) {
			return 1;
		}
	}
	return 0;

}

void main() {

	setlocale(LC_ALL, ".1251");

	cout << "¬ведите промежуток: ";
	double a, b;
	cin >> a >> b;

	double i = b;
	while (i >= a) {

		double x = Newton(i);
		if (!checkX(x) && x <= b && x >= a) {
			Xi.push_back(x);
		}
		i -= h;

	}
	sort(Xi.begin(), Xi.end());

	for (double x : Xi) {
		cout << "x = " << x << endl;
	}
}