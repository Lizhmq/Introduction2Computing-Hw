#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[10000010];

int MAP(char c)
{
	if (c <= '9' && c >= '0')
		return c - '0';
	if (c >= 'A' && c <= 'P')
		return (c - 'A') / 3 + 2;
	if (c >= 'R' && c <= 'Y')
		return (c - 'Q') / 3 + 7;
	cerr << "Wrong Input" << endl;
	exit(1);
}

int main()
{
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	char s[100];
	memset(cnt, 0, sizeof(cnt));
	while (k--) {
		cin >> s;
		int l = strlen(s);
		int num = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] == '-')
				continue;
			num = num * 10 + MAP(s[i]);
		}
		cnt[num]++;
	}
	int maxc = 0;
	for (int i = 0; i < 10000001; ++i)
		maxc = max(maxc, cnt[i]);
	if (maxc == 1) {
		cout << "No duplicates." << endl;
		return 0;
	}
	for (int i = 0; i < 10000001; ++i) {
		if (cnt[i] <= 1)
			continue;
		int tmp = i;
		for (int j = 0; j < 4; ++j) {
			s[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		s[4] = '-';
		for (int j = 5; j < 8; ++j) {
			s[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		s[8] = '\0';
		reverse(s, s + 8);
		cout << s << ' ' << cnt[i] << endl;
	}
	return 0;
}