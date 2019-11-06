#include <iostream>
#include <cstring>
using namespace std;

char s[1000][100];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int curidx = 0;
	for (int i = 0; i < n; ++i) {
		int l = strlen(s[i]);
		if (curidx + l + 1 <= 80) {
			if (curidx != 0) {
				cout << ' ';
				curidx += 1;
			}
			cout << s[i];
			curidx += l;
		} else {
			cout << endl << s[i];
			curidx = l;
		}
	}
	return 0;
}