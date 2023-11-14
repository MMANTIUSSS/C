#include <iostream>
#include <fstream>
#pragma once
using namespace std;
double sigmoid(double xalpha)
{
	return 1 / (1 + exp(-xalpha));
}
void study(double* x, double* y) {
	double xalpha[20][18], Y[20], yalpha[25];
	for (int i = 0; i < 20; i++)
		Y[i] = 0;
	int Ques = 18, Us = 20;
	ifstream File("input.txt");
	if (!File.is_open())
	{
		cout << "Error." << endl;
	}
	else {
		for (int i = 0; i < Us; i++)
		{
			for (int j = 0; j < Ques; j++)
			{
				File >> xalpha[i][j];
			}
			File >> yalpha[i];

		}
	}

	for (int i = 0; i < Us; i++) {
		for (int j = 0; j < Ques; j++) {
			cout << xalpha[i][j] << " ";
		}
		cout << "\t";
		cout << yalpha[i] << endl;
	}

	double w[20][18], v[20][18], err[20];
	for (int i = 0; i < Us; i++)
	{
		for (int j = 0; j < Ques; j++) {
			v[i][j] = rand();
			w[i][j] = rand();
		}
	}
	double xHidd[20], xEx[20], yHidd[20], yEx[20], delta[20], sum[20];
	double h = 0.5;
	//скрытый слой
	for (int i = 0; i < Us; i++)
	{
		xHidd[i] = 0;
		for (int j = 0; j < Ques; j++)
		{
			xHidd[i] += xalpha[i][j] * w[i][j];
		}
	}
	for (int i = 0; i < Us; i++)
	{
		yHidd[i] = sigmoid(xHidd[i]);
	}
	for (int i = 0; i < Us; i++)
	{
		xEx[i] = 0;
		for (int j = 0; j < Ques; j++)
		{
			xEx[i] += v[i][j] * yHidd[i];
		}

	}
	for (int i = 0; i < Us; i++)
	{
		yEx[i] = sigmoid(xEx[i]);
	}
	cout << endl;
	double eps = 10e-7;
	double error;
	for (int p = 0; p < 10000 || error < eps; p++)
	{
		error = 0;
		for (int i = 0; i < Us; i++)
			for (int j = 0; j < Ques; j++)
				xHidd[i] += xalpha[i][j] * w[i][j];
		for (int i = 0; i < Us; i++)
			yHidd[i] = sigmoid(xHidd[i]);
		for (int i = 0; i < Us; i++)
		{
			xEx[i] = 0;
			for (int j = 0; j < Ques; j++)
				xEx[i] += v[i][j] * yHidd[i];

		}
		for (int i = 0; i < Us; i++)
		{
			yEx[i] = sigmoid(xEx[i]);
			delta[i] = yEx[i] - yalpha[i];
			error += delta[i];
		}
		for (int i = 0; i < Us; i++)
		{
			for (int j = 0; j < Ques; j++) {
				v[i][j] -= h * (delta[i] * yEx[i] * (1 - yEx[i]) * yHidd[i]);
			}
		}
		for (int i = 0; i < Us; i++)
		{
			sum[i] = 0;
			for (int j = 0; j < Ques; j++) {
				sum[i] += (delta[i] * yEx[i] * (1 - yEx[i]) * v[i][j]);
			}
		}
		for (int i = 0; i < Us; i++)
		{
			for (int j = 0; j < Ques; j++) {
				w[i][j] -= h * (sum[i] * (yHidd[i] * (1 - yHidd[i]) * xalpha[i][j]));
			}
		}
	}
	for (int i = 0; i < Us; i++)
		for (int j = 0; j < Ques; j++)
			xHidd[i] += xalpha[i][j] * w[i][j];
	for (int i = 0; i < Us; i++)
		yHidd[i] = sigmoid(xHidd[i]);
	for (int i = 0; i < Us; i++)
	{
		xEx[i] = 0;
		for (int j = 0; j < Ques; j++)
			xEx[i] += v[i][j] * yHidd[i];

	}
	for (int i = 0; i < Us; i++)
	{
		yEx[i] = sigmoid(xEx[i]);
		cout << yEx[i] << endl;}}
