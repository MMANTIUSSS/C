#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, S=0;
    int i, n;
    
    cout << "Input n: ";
    cin >> n;
    cout << "Input a:" << endl;
    for(i=0;i<n;i++)
    {
        cin >> a;
        b=a;
        while(b>0)
        {
            if (b%10==4)
            {
                b=0;
                S+=a;
            }
            else
            b/=10;
        }
    }
    if (S>1)
        cout << "Result: " << S;
    else
        cout << "No result.";
    system("pause");
    return 0;
}