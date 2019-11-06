#include <iostream>
using namespace std;

#define MAXN 10000
bool nprime[MAXN +10];
bool factor1[MAXN], factor2[MAXN];

int main()
{
	int a, b;
	char c;
	cin >> a >> c >> b;
	nprime[0] = nprime[1] = true;
	for (int i = 2; i < MAXN; ++i) {
		if (nprime[i])
			continue;
		for (int j = i * 2; j < MAXN; j += i)
			nprime[j] = true;
	}
	for (int i = 2; i * i <= a; ++i)
		if (!nprime[i] && a % i == 0) {
			factor1[i] = true;
			while (a % i == 0)
				a /= i;
		}
	if (!nprime[a])
		factor1[a] = true;
	for (int i = 2; i * i <= b; ++i)
		if (!nprime[i] && b % i == 0) {
			factor2[i] = true;
			while (b % i == 0)
				b /= i;
		}
	if (!nprime[b])
		factor2[b] = true;
	bool flag = true;
	for (int i = 2; i <= max(a, b); ++i) {
		if (factor1[i] != factor2[i]) {
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}