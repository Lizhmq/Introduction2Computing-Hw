#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int grids[30][30], n;
	bool visited[30][30];
	memset(visited, 0, sizeof(visited));
	cin >> n;
	int num = 1;
	int i = 0, j = n / 2;
	while (num <= n * n) {
		grids[i][j] = num++;
		visited[i][j] = true;
		if (i == 0 && j == n - 1 
		    || i - 1 >= 0 && j + 1 < n && visited[i - 1][j + 1]) {
			i = i + 1;
		} else if (i == 0) {
			i = n - 1;
			j++;
		} else if (j == n - 1) {
			j = 0;
			i--;
		} else {
			i--, j++;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << grids[i][0];
		for (int j = 1; j < n; ++j)
			cout << ' ' << grids[i][j];
		cout << endl;
	}
	return 0;
}