#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int a[100][100], tmp;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			a[i][j] += tmp;
		}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (j > 0)
				cout << " " << a[i][j];
			else
				cout << a[i][j];
		cout << endl;
	}
	return 0;
}