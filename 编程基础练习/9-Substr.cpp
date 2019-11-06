#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s1[60], s2[60];
	cin >> s1 >> s2;
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	for (int i = 0; i < l2 - l1 + 1; ++i) {
		int cnt = 0;
		for (int j = 0; j < l1; ++j)
			cnt += s1[j] == s2[j + i];
		if (cnt == l1) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}