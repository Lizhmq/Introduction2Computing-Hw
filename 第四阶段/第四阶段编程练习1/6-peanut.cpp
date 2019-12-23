#include <algorithm>
#include <iostream>
using namespace std;

struct Peanut {
	int x, y;
	int value;
} ps[400];

bool cmp(const Peanut &a, const Peanut &b)
{
	return a.value > b.value || 
		a.value == b.value && a.x > b.y || 
		a.value == b.value && a.x == b.x && a.y > b.y;
}

int main()
{
	int k;
	cin >> k;
	while (k--) {
		int m, n, t, idx = 0;
		cin >> m >> n >> t;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				int tmp;
				cin >> tmp;
				if (tmp > 0) {
					ps[idx].value = tmp;
					ps[idx].x = i;
					ps[idx++].y = j;
				}
			}
		sort(ps, ps + idx, cmp);
		int res = 0, curx = 0, cury = 0, curidx = 0;
		while (t > 0 && curidx < idx) {
			int x = ps[curidx].x;
			int y = ps[curidx].y;
			if (res == 0) {
				if (t >= 2 * x + 3) {
					res += ps[curidx].value;
					curx = x;
					cury = y;
					t -= x + 2;
					curidx += 1;
				} else {
					break;
				}
			} else {
				int movcost = abs(x - curx) + abs(y - cury);
				if (t >= movcost + 1 + x + 1) {
					res += ps[curidx].value;
					curx = x;
					cury = y;
					t -= movcost + 1;
					curidx += 1;
				} else {
					break;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}