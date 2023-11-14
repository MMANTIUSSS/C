#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    struct student {
        string NSP;
        int age, groupnumber;
        int Math, Algebra, BP;
    };
    student a[10];
    student b[1];
    int n, i, k=0, j=0, z;
    cout << "Input n: ";
    cin >> n;
    for(i=0;i<n;i++) {
        cout << endl << "Input NSP_" << i+1 << ": ";
        cin >> a[i].NSP;
        cout << endl << "Input age: ";
        cin >> a[i].age;
        cout << endl << "Input groupnumber: ";
        cin >> a[i].groupnumber;
        cout << endl << "Input math-analysis grade: ";
        cin >> a[i].Math;
        cout << endl << "Input algebra grade: ";
        cin >> a[i].Algebra;
        cout << endl << "Input BP grade: ";
        cin >> a[i].BP;
    }
    
    for(i=0;i<n;i++) {
        if (a[i].Math < 3 || a[i].Algebra < 3 || a[i].BP < 3) {
            b[0] = a[k];
            a[k] = a[i];
            a[i] = b[0];
            k++;
        }
    }
    k--;
    for (z=0;z<k;z++) {
        for(i=0;i<k;i++) {
            j=0;
            while (int(a[i].NSP[j])==int(a[i+1].NSP[j]))
                j++;
            if (int(a[i].NSP[j])<int(a[i+1].NSP[j])) {
                b[0]=a[i];
                a[i]=a[i+1];
                a[i+1]=b[0];
            }
        }
    }
    for (z=0;z<n;z++) {
        for(i=k+1;i<n-1;i++) {
            j=0;
            while (int(a[i].NSP[j])==int(a[i+1].NSP[j]))
                j++;
            if (int(a[i].NSP[j])>int(a[i+1].NSP[j])) {
                b[0]=a[i];
                a[i]=a[i+1];
                a[i+1]=b[0];
            }
        }
    }
    for(i=0;i<n;i++)
        cout << a[i].NSP << endl;
        
    system("pause");
    return 0;
}