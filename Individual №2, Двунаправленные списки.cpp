// #include "stdafx.h"
#include <iostream>
using namespace std;

int function(int x) {
	int f, k, i;
	f = 0;
	k = 0;
	for (i = 1; i < x; i++)
		if (x % i == 0)
			f = f + i;
	if (x == f)
		k++;
	return k;
}

int main() {
	struct list {
		int info;
		list* R;
		list* L;
	};
	list* h1, * p, * r, * g, * q, * h2;
	int a = 0;
	h1 = new (list);
	int x;
	cin >> x;
	h1->info = x;
	h1->R = NULL;
	h1->L = NULL;
	p = h1;
	while (x != 0) {
		cin >> x;
		if (x != 0) {
			r = new(list);
			r->info = x;
			r->R = NULL;
			r->L = p;
			p->R = r;
			p = r;
		}
	}
	p = h1;
	while (p != NULL) {
		if (function(p->info) == 1) {
			if (a == 0) {
				h2 = new (list);
				h2->info = p->info;
				h2->L = NULL;
				h2->R = NULL;
				g = h2;
				a = 1;
			}
			else {
				q = new (list);
				q->info = p->info;
				q->R = NULL;
				q->L = g;
				g->R = q;
				g = q;
			}
		}
		p = p->R;
	}
	p = h1;
	while (p != NULL) {
		if (p->info > 0) {
			if (a == 0) {
				h2 = new (list);
				h2->info = p->info;
				h2->L = NULL;
				h2->R = NULL;
				g = h2;
				a = 1;
			}
			else {
				q = new (list);
				q->info = p->info;
				q->R = NULL;
				q->L = g;
				g->R = q;
				g = q;
			}
		}
		p = p->R;
	}
	p = h1;
	while (p != NULL) {
		if (p->info < 0) {
			if (a == 0) {
				h2 = new (list);
				h2->info = p->info;
				h2->L = NULL;
				h2->R = NULL;
				g = h2;
				a = 1;
			}
			else {
				q = new (list);
				q->info = p->info;
				q->R = NULL;
				q->L = g;
				g->R = q;
				g = q;
			}
		}
		p = p->R;
	}
	p = h2;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->R;
	}
	system("pause");
	return 0;
}