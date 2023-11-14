#include <iostream>
using namespace std;

// Дано дерево. Если в нем больше 2-х элементов, в записи которых встречается цифра 3 и не встречается цифра 5, то увеличить все четные элементы на значение максимального.
// Иначе уменьшить все нечетные на значение минимального.

struct tree
{
	int info;
	tree* L;
	tree* R;
};

void _add(tree* t, int x)
{
	tree* q;
	if (x < t->info)
		if (t->L == NULL)
		{
			q = new (tree);
			q->info = x;
			q->L = NULL;
			q->R = NULL;
			t->L = q;
		}
		else
			_add(t->L, x);
	else
		if (t->R == NULL)
		{
			q = new (tree);
			q->info = x;
			q->L = NULL;
			q->R = NULL;
			t->R = q;
		}
		else
			_add(t->R, x);
}


void _print(tree* p) 
{
	if (p != NULL)
	{
		cout << endl << p->info << "    ";
		_print(p->L);
		_print(p->R);
	}
}

void _numbers(tree* p, int x, int& k) {
	if (p != NULL)
		while (x != 0) {
			if (x % 10 == 3 && x % 10 != 5)
				k++;
			x /= 10;
	}
	_numbers(p->L, x, k);
	_numbers(p->R, x, k);
}

void min_max(tree* p, int& min, int& max) {

}

void main()
{
	int x, k = 0;
	tree* root = new (tree);
	cout << "Input x: " << endl;
	cin >> x;
	root->info = x;
	root->L = NULL;
	root->R = NULL;

	while (x != 0)
	{
		cin >> x;
		if (x != 0)
			_add(root, x);
	}

	_numbers(root, x, k);
	min_max(root, x)
	_function(root, min, max);

	_print(root);
}