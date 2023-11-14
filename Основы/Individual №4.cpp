#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    int a[3][3];
    int b[10];
    int n = 3;
    int i, j, k;
    int min, S = 0, z, y, P = 0;
    
    cout << "Input a[i][j]" << endl;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    for (i=0; i<n; i++)
    {
        y=a[i][0];
        while (y>0)
            {
             P=P+y%10;
             y/=10;
            }
        min = P;
        for (j=0; j<n; j++)
        {
            S = 0;
            z=a[i][j];
            while(z>0)
            {
                S=S+z%10;
                z = z/10;
            }
            if (S < min)
            min = S;
        }
        b[i]=min;
    }
    cout << "Result:" << endl;
    for (i=0; i<n; i++)
        cout << b[i] << " ";
    system("pause");
    return 0;
}