#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char *fillint2char(int num, char *p)
{
	int cnt = 0;
	while (num) {
		*p++ = num % 10 + '0';
		num /= 10;
		cnt += 1;
	}
	reverse(p - cnt, p);
	*p = '\0';
	return p;
}

void encode(char src[], char *tgt)
{
	int idx = 0;
	int l1 = strlen(src);
	while (idx < l1) {
		int newidx = idx + 1;
		while (newidx < l1 && src[newidx] == src[newidx - 1])
			newidx++;
		tgt = fillint2char(newidx - idx, tgt);
		*tgt++ = src[newidx - 1];
		*tgt = '\0';
		idx = newidx;
	}
}

int main()
{
	char s[1010], t[2010];
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		encode(s, t);
		cout << t << endl;
	}
	return 0;
}