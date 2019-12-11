#include <iostream>
#include <iomanip>
using namespace std;

int func(int n, int start)
{
	int res = 0;
	for (int i = start; i * i <= n; ++i)
		if (n % i == 0)
			res += func(n / i, i);
	return res + 1;
}

int main()
{
	int k, n;
	cin >> k;
	while (k--) {
		cin >> n;
		cout << func(n, 2) << endl;
	}
	return 0;
}