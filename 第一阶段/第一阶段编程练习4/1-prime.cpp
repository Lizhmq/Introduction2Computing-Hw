#include <iostream>
using namespace std;

bool check(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int m, k;
	cin >> m >> k;
	m += 1;
	while (k--) {
		while (!check(m))
			m++;
		cout << m;
		if (k != 0)
			cout << " ";
		m++;
	}
	return 0;
}