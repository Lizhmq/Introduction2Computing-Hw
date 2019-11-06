#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;

struct Group {
	double grow;
	int id;
} g[100];

bool cmp(const Group &a, const Group &b)
{
	return a.grow < b.grow || a.grow == b.grow && a.id < b.id;
}

int main()
{
	int n;
	double a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> g[i].id;
		cin >> a >> b;
		g[i].grow = b / a;
	}
	sort(g, g + n, cmp);
	double ave = (g[0].grow + g[n - 1].grow) / 2;
	int split = 0;
	while (split < n && g[split].grow < ave)
		split++;
	cout << n - split << endl;
	for (int i = split; i < n; ++i)
		cout << g[i].id << endl;
	cout << split << endl;
	for (int i = 0; i < split; ++i)
		cout << g[i].id << endl;
	return 0;
}