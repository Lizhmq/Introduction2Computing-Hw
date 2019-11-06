#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

bool out(int n, int i, int j)
{
	return i < 0 || j < 0 || i >= n || j >= n;
}

int main()
{
	int mat[15][15];
	int n;
	cin >> n;
	int i = 0, j = 0, cnt = 0;
	bool rightup = true;		// moving direction
	while (cnt < n * n) {
		mat[i][j] = ++cnt;
		if (rightup) {
			if (out(n, i - 1, j + 1)) {	// reach boudary of matrix
				if (out(n, i, j + 1))	// can not move to right, move down
					i++;
				else			// can move to right
					j++;
				rightup = !rightup;	// change direction if reach boudary
			} else {
				i--, j++;
			}
		} else {
			if (out(n, i + 1, j - 1)) {
				if (out(n, i + 1, j))
					j++;
				else
					i++;
				rightup = !rightup;
			} else {
				i++, j--;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (j > 0)
				cout << " " << mat[i][j];
			else
				cout << mat[i][j];
		cout << endl;
	}
	return 0;
}