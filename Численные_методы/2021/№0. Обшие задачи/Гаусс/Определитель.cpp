#include <iostream>
#include <fstream>
using namespace std;

int i, j, k, l, p = 1;
double alpha, beta, delta = 1;

void matrix_output(double** matrix, int n);

void gauss_method(double** matrix, int n);

int main() {
    setlocale(LC_ALL, "rus");
    ifstream input("2.txt");

    int n; input >> n;

    double** matrix = new double* [n];
    for (i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }

    cout << "Matrix:\n";
    matrix_output(matrix, n);

    // Прямой ход метода Гаусса
    gauss_method(matrix, n);

    // Вычисление и вывод определителя
    double det = 1;
    for (i = 0; i < n; i++) {
        det *= matrix[i][i];
    }
    cout << "Определитель матрицы: " << det * p * delta << endl;

    delete[] matrix;

    system("pause");
    return 0;
}

// Вывод преобразованной матрицы
void matrix_output(double** matrix, int n) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void gauss_method(double** matrix, int n) {
    for (k = 0; k < n; k++)
    {
        // Поиск максимального по модулю(главного) элемента в столбце
        alpha = abs(matrix[k][k]);
        i = k;
        for (l = k + 1; l < n; l++)
            if (abs(matrix[l][k]) > alpha)
            {
                i = l;
                alpha = abs(matrix[l][k]);
            }

        // Проверка его на равенство нулю
        if (alpha == 0) { break; }

        // Перестановка строки, содержащей главный элемент
        if (i != k)
        {
            p *= -1;
            for (j = k; j < n; j++)
            {
                beta = matrix[k][j];
                matrix[k][j] = matrix[i][j];
                matrix[i][j] = beta;
            }
        }

        // Преобразование k-ой строки с помощью масштабирующих множителей
        alpha = matrix[k][k];
        delta *= alpha;
        matrix[k][k] = 1;
        for (j = k + 1; j < n; j++)
            matrix[k][j] = matrix[k][j] / alpha;

        // Преобразование строк с помощью k-ой строки
        for (i = k + 1; i < n; i++)
        {
            beta = matrix[i][k];
            matrix[i][k] = 0;
            if (beta != 0)
                for (j = k + 1; j < n; j++)
                    matrix[i][j] = matrix[i][j] - beta * matrix[k][j];
        }
    }
}