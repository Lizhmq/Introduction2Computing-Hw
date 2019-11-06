#include <iostream>
using namespace std;

bool check(int n)
{
	if (n % 7 == 0)
		return true;
	while (n) {
		if (n % 10 == 7)
			return true;
		n /= 10;
	}
	return false;
}

int main()
{
	bool site[100] = { false };
	int n, cnt = 0, idx = 0, num = 1;
	cin >> n;
	while (cnt < n) {
		if (!site[idx]) {
			if (check(num)) {
				cout << idx + 1 << endl;
				site[idx] = true;
				cnt += 1;
			}
			num += 1;
		}
		idx = (idx + 1) % n;
	}
	return 0;
}