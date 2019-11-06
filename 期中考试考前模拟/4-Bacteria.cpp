#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int num1[9][9], num2[9][9];
	int m, n;
	memset(num1, 0, sizeof(num1));
	cin >> num1[4][4] >> n;
	while (n--) {
		memset(num2, 0, sizeof(num2));
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (num1[i][j] > 0) {
					for (int x = i - 1; x <= i + 1; ++x)
						for (int y = j - 1; y <= j + 1; ++y)
							num2[x][y] += num1[i][j];
				}
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				num1[i][j] += num2[i][j];
	}
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (j == 8)
				cout << num1[i][j] << endl;
			else
				cout << num1[i][j] << ' ';
	return 0;
}