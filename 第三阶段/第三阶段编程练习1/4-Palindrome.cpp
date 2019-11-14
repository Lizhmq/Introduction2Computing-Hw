#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool palind(int n)
{
	char s1[10], s2[10];
	int idx = 0;
	while (n) {
		s1[idx++] = n % 10 + '0';
		n /= 10;
	}
	s1[idx] = '\0';
	strcpy(s2, s1);
	reverse(s2, s2 + idx);
	return strcmp(s1, s2) == 0;
}

int main()
{
	int n;
	cin >> n;
	cout << (palind(n) ? "yes" : "no") << endl;
	return 0;
}