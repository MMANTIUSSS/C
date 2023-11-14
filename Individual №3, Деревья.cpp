#include <iostream>
using namespace std;

// Дано дерево двоичного поиска. Найти кол-во уровней дерева.

struct tree {
	int info;
	int lvl;	// добавление понятия "уровень"
	tree* L;
	tree* R;
};	

void function(tree* t, int& k) {	// расчет уровней, вывод результата
	if (t != NULL) {
		if (k < t->lvl)
			k++;
		function(t->L, k);
		function(t->R, k);
	}
}
void add_lvl(tree* t, int x, int y) {	// построение дерева с записей уровней
	tree* q;
	if (x < t->info)
		if (t->L == NULL) {
			q = new (tree);
			q->info = x;
			q->lvl = y;
			q->L = NULL;
			q->R = NULL;
			t->L = q;
		}
		else
			add_lvl(t->L, x, y + 1);
	else
		if (t->R == NULL) {
			q = new (tree);
			q->info = x;
			q->lvl = y;
			q->L = NULL;
			q->R = NULL;
			t->R = q;
		}
		else
			add_lvl(t->R, x, y + 1);
}

void _print(tree* t) {		// вывод из дерева
	if (t != NULL) {
		cout << t->info << "  ";
		_print(t->L);
		_print(t->R);
	}
}

void main() {
	int k = 0;
	int x, y = 1;
	tree* root = new (tree);
	cout << "Input x: ";
	cin >> x;
	root->info = x;
	root->L = NULL;
	root->R = NULL;
	while (x != 0) {	// запись в дерево
		cout << "Input x: ";
		cin >> x;
		if (x != 0) {
			add_lvl(root, x, y);
		}
	}
	function(root, k);
	cout << endl << "Result: " << k << endl;
	_print(root);
}