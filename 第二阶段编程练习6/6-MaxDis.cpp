#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	char s[320], s1[20], s2[20];
	cin.getline(s, 302, ',');
	cin.getline(s1, 12, ',');
	cin.getline(s2, 12);
	int l = strlen(s);
	int l1 = strlen(s1);
	int l2 = strlen(s1);
	char *find1 = strstr(s, s1);
	char *find2 = NULL;
	int j = l - 1;
	while (find2 == NULL && j >= 0)
		find2 = strstr(s + j--, s2);
	if (find1 == NULL || find2 == NULL)
		cout << -1 << endl;
	else {
		int res = find2 - find1 - l1;
		cout << ((res >= 0) ? res : -1) << endl;
	}
	return 0;
}