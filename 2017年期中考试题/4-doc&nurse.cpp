#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

bool related4(int n)
{
	if (n % 4 == 0)
		return true;
	while (n) {
		if (n % 10 == 4)
			return true;
		n /= 10;
	}
	return false;
}

int main()
{
	int n, res = 0, num = 1, k = 0;
	cin >> n;
	while (k < 10) {
		while (related4(num))
			num++;
		res += num;
		num++, k++;
	}
	cout << res << endl;
	return 0;
}