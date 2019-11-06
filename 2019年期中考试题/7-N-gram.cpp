#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[510];
char words[500][10];
int words_idx;
char tmp[10];
int cnts[500];

int main()
{
	int k;
	cin >> k >> s;
	int l = strlen(s);
	for (int i = 0; i < l - k + 1; ++i) {
		char saved = s[i + k];
		s[i + k] = '\0';
		strcpy(tmp, s + i);
		s[i + k] = saved;
		bool flag = false;
		for (int i = 0; i < words_idx; ++i) {
			if (strcmp(words[i], tmp) == 0) {
				cnts[i]++;
				flag = true;
				break;
			}
		}
		if (!flag)
			strcpy(words[words_idx++], tmp);
	}
	int maxn = 0;
	for (int i = 0; i < words_idx; ++i)
		maxn = max(maxn, cnts[i]);
	if (maxn == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << maxn + 1 << endl;
	for (int i = 0; i < words_idx; ++i)
		if (cnts[i] == maxn)
			cout << words[i] << endl;
	return 0;
}