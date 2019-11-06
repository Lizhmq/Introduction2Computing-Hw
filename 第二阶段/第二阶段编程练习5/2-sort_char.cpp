#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char s[1010];
	cin.get(s, 1000);
	int l = strlen(s);
	sort(s, s + l / 2);
	reverse(s, s + l);
	reverse(s, s + l / 2);
	cout << s << endl;
	return 0;
}