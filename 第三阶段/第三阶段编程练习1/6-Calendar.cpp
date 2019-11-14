#include <iostream>
#include <cstring>
using namespace std;

const char tzol[20][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi",
			 "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben",
			 "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
const char haab[20][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
			 "mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
			 "muan", "pax", "koyab", "cumhu", "uayet" };


int main()
{
	int k;
	cin >> k;
	cout << k << endl;
	while (k--) {
		int day, month, year;
		char c;
		char s[10];
		cin >> day >> c >> s >> year;
		for (int i = 0; i < 19; ++i)
			if (strcmp(haab[i], s) == 0)
				month = i;
		int D = month * 20 + day;
		D += year * 365;
		year = D / 260;
		D %= 260;
		month = D % 13;
		D = D % 20;
		cout << month + 1 << " " << tzol[D] << ' ' << year << endl;
	}
	return 0;
}								