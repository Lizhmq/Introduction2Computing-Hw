#include <iostream>
using namespace std;

int acc[100010];

int func(int num)
{
	int res = 0;
	for (int i = 1; i * i <= num; ++i) {
		if (num % i == 0) {
			res += i;
			if (i != num / i && i != 1)
				res += num / i;
		}
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		acc[i] = func(i);
	for (int i = 1; i < n; ++i)
		if (i < acc[i] && acc[i] <= n && acc[acc[i]] == i)
			cout << i << ' ' << acc[i] << endl;
	return 0;
}