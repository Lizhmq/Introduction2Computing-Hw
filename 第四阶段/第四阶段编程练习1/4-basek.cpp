#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void addone(char s[], int k)
{
	int l = strlen(s);
	reverse(s, s + l);
	s[l] = '0';
	s[0] += 1;
	for (int i = 0; i < l; ++i) {
		s[i + 1] += (s[i] - '0') / k;
		s[i] = (s[i] - '0') % k + '0';
	}
	if (s[l] != '0')
		l++;
	s[l] = '\0';
	reverse(s, s + l);
	return;
}

int main()
{
	int k, m;
	char s[1010], c;
	cin >> k >> c >> m >> c >> s;
	for (int i = 0; i < m; ++i) {
		addone(s, k);
		cout << s;
		if (i != m - 1)
			cout << (i % 5 == 4 ? '\n' : ',');
	}
	cout << endl;
	return 0;
}