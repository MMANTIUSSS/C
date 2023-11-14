#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    int a[10];
    int i,j,n,k=0,v=0;
    int S=0;
    
    cout << "Input n: ";
    cin >> n;
    cout << "Input a[i]:" << endl;
    for(i=0;i<n;i++)
        cin >> a[i];
    for(i=0;i<n;i++)
    {
        S=0;
        for(j=1;j<a[i];j++)
            if (a[i]%j==0)
                S=S+j;
        if (S==a[i])
        v++;
    }
    if (v>=3)
    {
        for(i=0;i<n;i++)
                if (a[i]<0)
                    a[i]=0;
    }
    else 
    {
        for(i=0;i<n;i++)
                if (a[i]>0)
                    a[i]=a[i]*2;
    }
    cout << "Result: " << endl;
    for(i=0;i<n;i++)
        cout << a[i] << " ";
    system("pause");
    return 0;
}