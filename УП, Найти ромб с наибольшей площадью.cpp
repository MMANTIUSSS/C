#include <iostream>
#include <cmath>
using namespace std;

struct point {   // точки из х & y
    float x, y;
};

float function(float x, float min, float lim = 0) {   // нахождение минимума
    if (x < min && x > lim)
        min = x;
    return min;
}

float find_romb_s(point romb[4]) {   // нахождение диагоналей ромба -> S ромба
    float d1, d2, a;
    d1 = sqrt(pow(romb[0].x - romb[3].x, 2) + pow(romb[0].y - romb[3].y, 2));
    d2 = sqrt(pow(romb[1].x - romb[2].x, 2) + pow(romb[1].y - romb[2].y, 2));
    return (d1 * d2 / 2.0);
}

int main() {

    point a[15], romb[4];
    float data[15][15], for_min_find, last_lim = -1, new_lim = -2;
    bool found = false, second = false;
    float max_s = 0, some_s = 0;   // максимальная площадь, площадь в real time
    int i, j, n, k, p, l, m, tmp;

    cout << "Input the amount of points: ";   // ввод точек
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input coordinates of " << "point_" << i + 1 << ":";
        cin >> a[i].x >> a[i].y;
    }

    for (i = 0; i < n; i++) {   // -1 на главной диагонали, расчет расстояния между точками
        for (j = 0; j < n; j++) {
            if (i == j) {
                data[i][j] = -1;
            }
            else {
                data[i][j] = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
                data[j][i] = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
            }
        }
    }

    found = false;
    for (i = 0; i < n && !found; i++) {   // нахождение min
        for (j = i + 1; j < n && !found; j++) {
            if (data[i][j] > last_lim) {
                for_min_find = data[i][j];
                found = true;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            new_lim = function(data[i][j], for_min_find, last_lim);
            for_min_find = new_lim;
        }
    }

    bool s_found = false;
    while (last_lim != new_lim) {  
        for (i = 0; i < n; i++) {   // нахождение 3x точек по строкам из матрицы
            romb[0] = a[i];
            p = 1;
            second = false;
            s_found = false;
            for (j = 0; j < n && s_found != true; j++) {
                if (data[i][j] == new_lim && p < 3) {
                    romb[p] = a[j];
                    p++;
                    if (!second) {
                        tmp = j;
                        second = true;
                    }
                }

                if (p == 3)   // нахождение 4й точки по столбцу из матрицы
                    for (l = tmp, m = j, k = 0; k < n; k++)
                        if (data[l][k] == new_lim && data[m][k] == new_lim && k != i) {
                            romb[3] = a[k];
                            p++;
                            break;
                        }

                if (p == 4)   // нахождение стороны ромба и S соответственно
                    some_s = find_romb_s(romb);
                    if (some_s > max_s) {
                        max_s = some_s;
                        s_found = true;
                    }

            }
        }

        last_lim = new_lim;

        found = false;
        for (i = 0; i < n && !found; i++) {   // нахождение следующего min
            for (j = i + 1; j < n && !found; j++) {
                if (data[i][j] > last_lim) {
                    for_min_find = data[i][j];
                    found = true;
                }
            }
        }

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                new_lim = function(data[i][j], for_min_find, last_lim);
                for_min_find = new_lim; 
            }
        }

    }
    cout << endl;

    if (max_s == 0)
        cout << "No result." << endl;
    else
        cout << "Result: " << max_s << endl;

    return 0;
}