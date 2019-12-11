#include <iostream>
#include <cstring>
using namespace std;

int mem[22][22];

bool match(char s1[], char s2[], int i, int l1, int j, int l2)
{
	if (mem[i][j] != -1)
		return mem[i][j] == 1;
	if (i == l1)
		return mem[i][j] = j >= l2;
	if (s1[i] == '?')
		return mem[i][j] = match(s1, s2, i + 1, l1, j + 1, l2);
	if (s1[i] == '*') {
		for (int p = j; p <= l2; ++p)
			if (match(s1, s2, i + 1, l1, p, l2))
				return mem[i][j] = 1;
		return mem[i][j] = 0;
	}
	return mem[i][j] = j < l2 && s2[j] == s1[i] && match(s1, s2, i + 1, l1, j + 1, l2);
}

int main()
{
	char s1[22], s2[22];
	memset(mem, -1, sizeof(mem));
	cin >> s1 >> s2;
	cout << (match(s1, s2, 0, strlen(s1), 0, strlen(s2)) ? "matched" : "not matched") << endl;
	return 0;
}