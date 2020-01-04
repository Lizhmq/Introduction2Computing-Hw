#include <iostream>
using namespace std;

int main()
{
	int T;
	int array[200];
	cin >> T;
	while (T--) {
		int n, m, cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			int t = 0, tmp;
			for (int j = 0; j < m; ++j) {
				cin >> tmp;
				t += tmp;
			}
			if (t * 2 >= m)
				cnt += 1;
		}
		cout << cnt << endl;
	}
	return 0;
}