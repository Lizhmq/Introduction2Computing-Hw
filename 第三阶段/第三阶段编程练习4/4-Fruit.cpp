#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char c[1010];
	const char fruits[][15] = {"apples", "bananas", "peaches", "cherries", "pears", "oranges", "strawberries"};
	const char fail[] = "You must not enjoy fruit.";
	const char replace[] = "Brussels sprouts";
	while (cin.getline(c, 1002)) {
		bool got = false;
		int match = 0;
		int l = strlen(c);
		char *s;
		for (int j = 0; j < 7; ++j) {
			s = strstr(c, fruits[j]);
			if (s != NULL) {
				got = true;
				match = j;
				break;
			}
		}
		if (!got) {
			cout << fail << endl;
		} else {
			*s = '\0';
			cout << c << replace << s + strlen(fruits[match]) << endl;
		}
	}
	return 0;
}