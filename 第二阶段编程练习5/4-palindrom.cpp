#include <iostream>
#include <cstring>
using namespace std;

bool judge(char s[])
{
	int l = strlen(s);
	int i = 0, j = l - 1;
	while (i < j) {
		if (s[i] == s[j])
			i++, j--;
		else
			return false;
	}
	return true;
}

int main()
{
	char s[110];
	cin >> s;
	cout << (judge(s) ? "yes" : "no") << endl;
	return 0;
}