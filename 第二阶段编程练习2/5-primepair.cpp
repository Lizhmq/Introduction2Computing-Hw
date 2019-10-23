#include <iostream>
#include <cstdio>
using namespace std;

bool nprime[200001];

int main()
{
	int m, n;
	char c;
	cin >> m >> c >> n;
	nprime[0] = nprime[1] = true;
	for (int i = 2; i <= n; ++i) {
		if (nprime[i])
			continue;
		for (int j = i * 2; j <= n; j += i)
			nprime[j] = true;
	}
	bool flag = false;
	for (int i = m; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (!nprime[i] && !nprime[j] && !nprime[j - i]) {
				printf("(%d,%d)\n", i, j);
				flag = true;
			}
	if (!flag)
		cout << "NULL" << endl;
	return 0;
}