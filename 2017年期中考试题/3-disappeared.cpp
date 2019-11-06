#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int n, tmp;
	bool seen[110] = {false};
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		seen[tmp] = true;
	}
	for (int i = 1; i <= n; ++i)
		if (!seen[i])
			cout << i << endl;
	return 0;
}