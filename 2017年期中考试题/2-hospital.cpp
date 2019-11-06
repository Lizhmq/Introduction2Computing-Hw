#include <algorithm>
#include <iostream>
using namespace std;

struct People {
	int id;
	int key;
	friend bool operator < (const People &a, const People &b) {
		return a.key > b.key || a.key == b.key && a.id < b.id;
	}
} peo[10000];

int main()
{
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			peo[i].id = i + 1;
			cin >> peo[i].key;
		}
		sort(peo, peo + n);
		k = min(k, n);
		cout <<  k << endl;
		for (int i = 0; i < k; ++i) {
			if (i == k - 1)
				cout << peo[i].id << endl;
			else
				cout << peo[i].id << ' ';
		}
	}
	return 0;
}