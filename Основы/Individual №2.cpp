#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    int i, n;
    int a = 1;
    int b, c;
    float S = 0;
    
    cout << "Input n: ";
    cin >> n;
    for(i=1; i<=n; i++)
    {
        if(i==1);
        else 
        a *= a;
        b = 2 * i + 4;
        c=1;
        int k;
        for(k=1; k<b; k++)
        c *= k;
        S += (float) a / c;
    }
    cout << "Result: " << S;
    system("pause");
    return 0;
}