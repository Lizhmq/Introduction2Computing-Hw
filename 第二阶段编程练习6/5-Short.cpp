#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool isShort(char s1[], char s2[])
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (l1 >= l2)
		return false;
	int i = 0, j = 0;
	while (i < l1) {
		while (j < l2 && s2[j] != s1[i])
			j++;
		if (j == l2)
			return false;
		i++, j++;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	cin.get();
	char s1[32], s2[320];
	while (n--) {
		cin.getline(s1, 31, ':');
		cin.getline(s2, 310);
		cout << (isShort(s1, s2) ? "YES" : "NO") << endl;
	}
	return 0;
}