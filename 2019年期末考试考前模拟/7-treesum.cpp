#include <algorithm>
#include <iostream>
using namespace std;

struct {
	int l, r;
	int n;
	int val;
} a[110];

void calval(int k)
{
	if (a[k].l == 0 && a[k].r == 0)
		return;
	if (a[k].l != 0) {
		calval(a[k].l);
		a[k].val += a[a[k].l].val;
	}
	if (a[k].r != 0) {
		calval(a[k].r);
		a[k].val += a[a[k].r].val;
	}
	return;
}

int search(int k)
{
	if (a[k].l == 0 && a[k].r == 0)
		return k;
	if (a[k].l == 0)
		return search(a[k].r);
	if (a[k].r == 0)
		return search(a[k].l);
	if (a[a[k].l].val < a[a[k].r].val)
		return search(a[k].r);
	return search(a[k].l);
}

int main()
{
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].val;
			a[i].l = a[i].r = 0;
			a[i].n = i;
		}
		for (int i = 0; i < n - 1; ++i) {
			int y1, y2, type;
			cin >> y1 >> y2 >> type;
			if (type == 0)
				a[y1].l = y2;
			else
				a[y1].r = y2;
		}
		calval(1);
		cout << search(1) << endl;
	}
	return 0;
}