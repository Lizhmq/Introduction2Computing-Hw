#include <cstring>
#include <iostream>
using namespace std;

void strip(char *s)
{
	int l = strlen(s);
	int idx = 0;
	for (int i = 0; i <= l; ++i)
		if (s[i] != ' ')
			s[idx++] = s[i];
}

void CNT(char *s, int &cnt1, int &cnt2)
{
	strip(s);
	int l = strlen(s);
	const char word[4][10] = { "if", "switch", "while", "for" };
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < 4; ++j) {
			char saved = s[i + strlen(word[j])];
			s[i + strlen(word[j])] = '\0';
			if (strcmp(word[j], s + i) == 0 && saved == '(') {
				if (i < 2)
					cnt1 += 1;
				else
					cnt2 += 1;
			}
			s[i + strlen(word[j])] = saved;
		}
	}
}

int main()
{
	char s[1010];
	int n1, n2, cnt11 = 0, cnt12 = 0, cnt21 = 0, cnt22 = 0;
	cin >> n1;
	cin.get();
	while (n1--) {
		cin.getline(s, 1000);
		CNT(s, cnt11, cnt12);
	}
	cin >> n2;
	cin.get();
	while (n2--) {
		cin.getline(s, 1000);
		CNT(s, cnt21, cnt22);
	}
	bool res = cnt11 == cnt21 && cnt12 == cnt22;
	cout << (res ? "Yes" : "No") << endl;
	return 0;
}