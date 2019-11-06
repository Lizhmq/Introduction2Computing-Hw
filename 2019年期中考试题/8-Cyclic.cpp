#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[200], s2[200];

bool iscycl(char s1[], char s2[])
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (l1 != l2)
		return false;
	for (int i = 1; i < l1; ++i) {
		int cnt = 0;
		for (int j = 0; j < l1; ++j)
			if (s1[j] == s2[(j + i) % l1])
				cnt += 1;
		if (cnt == l1)
			return true;
	}
	return false;
}

void add(char s1[], char s2[])
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);		// in fact, l1 equals with l20
	reverse(s1, s1 + l1);
	reverse(s2, s2 + l2);
	for (int i = 0; i < l1; ++i) {
		s1[i + 1] += (s1[i] - '0' + s2[i] - '0') / 10;
		s1[i] = (s1[i] - '0' + s2[i] - '0') % 10 + '0';
	}
	reverse(s1, s1 + l1);
	reverse(s2, s2 + l1);
}

int main()
{
	while (cin >> s1) {
		strcpy(s2, s1);
		int l1 = strlen(s1);
		bool flag = true;
		for (int i = 0; i < l1 - 1; ++i) {
			add(s1, s2);
			if (s1[l1] != '\0' || !iscycl(s1, s2)) {		// 如果发生了进位，不是循环数
				flag = false;
				break;
			}
		}
		cout << s2;
		cout << (flag ? " is cyclic" : " is not cyclic") << endl;
	}
	return 0;
}