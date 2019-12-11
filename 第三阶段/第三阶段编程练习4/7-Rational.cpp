#include <cstring>
#include <iostream>
using namespace std;

int solve(int p, int q)
{
	if (p == 1 && q == 1)
		return 1;
	if (p > q)
		return 2 * solve(p - q, q) + 1;
	return 2 * solve(p, q - p);
}

int main()
{
	int n, p, q;
	cin >> n;
	while (n--) {
		cin >> p >> q;
		cout << solve(p, q) << endl;
	}
	return 0;
}