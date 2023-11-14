#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    struct list
    {
        int info;
        list* R;
    };
    list *h1, *h2, *h3, *p, *r, *q, *g;
    int f = 0, b;
    h1 = new (list);
    int x;
    cin >> x;
    h1->info = x;
    h1->R = NULL;
    p = h1;
    while (x != 0)
    {
        cin >> x;
        if (x != 0)
        {
            r = new(list);
            r->info = x;
            r->R = NULL;
            p->R = r;
            p = r;
        }
    }
  

    h3 = new (list);
    h3->R = NULL;
    q = h3;

    p = h1;
    while (p != NULL)
    {
        f = 0;
        b = p->info;
        while (b != 0)
        {
            if (b % 5 == 0)
                f = 1;
            b = b / 10;
        }
        if (f == 1)
        {
            q->info = p->info;
            g = new (list);
            g->R = NULL;
            q->R = g;
            q = q->R;
        }
        p = p->R;
    }

    h2 = new (list);
    cin >> x;
    h2->info = x;
    h2->R = NULL;
    p = h2;
    while (x != 0)
    {
        cin >> x;
        if (x != 0)
        {
            r = new(list);
            r->info = x;
            r->R = NULL;
            p->R = r;
            p = r;
        }
    }

    p = h2;
    while (p != NULL)
    {
        f = 0;
        b = p->info;
        while (b != 0)
        {
            if (b % 5 == 0)
                f = 1;
            b = b / 10;
        }
        if (f == 1)
        {
            q->info = p->info;
            g = new (list);
            g->R = NULL;
            q->R = g;
            q = q->R;
        }
        p = p->R;
    }
    
    q = h3;
    while (q->R != NULL)
    {
        cout << q->info << " ";
        q = q->R;
    }
    system("pause");
    return 0;
}