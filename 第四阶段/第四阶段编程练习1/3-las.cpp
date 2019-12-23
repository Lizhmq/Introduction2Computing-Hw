#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int num[5010];
int length[5010][5010];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	sort(num, num + n);
	int maxn = 0, v1, v2;
	for (int i = 1; i < n; ++i) {
		int p = 0;
		for (int j = 0; j < i; ++j) {
			length[j][i] = 2;
			while (p < j && num[p] + num[i] < 2 * num[j])
				p++;
			if (num[p] + num[i] == 2 * num[j])
				length[j][i] = length[p][j] + 1;
			if (length[j][i] > maxn ||
				length[j][i] == maxn && num[i] - num[j] >= num[v1] - num[v2]) {
				maxn = length[j][i];
				v1 = i;
				v2 = j;
			}
		}
	}
	int i = 0, j = 0;
	while (true) {
		while (j < n && num[j] == num[i])
			j++;
		if (j - i > maxn) {
			maxn = j - i;
			v1 = v2 = i;
		}
		if (j == n)
			break;
		i = j;
	}
	if (maxn < 3) {
		cout << "NO" << endl;
	} else {
		int val1 = num[v1];
		int dif = val1 - num[v2];
		cout << val1 - dif * (maxn - 1);
		for (int i = 0; i < maxn - 1; ++i)
			cout << ',' << val1 - dif * (maxn - 2 - i);
		cout << endl;
	}
	return 0;
}