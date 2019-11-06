#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

bool getpattern(char s[], int l, const char pattern[],  double *res)
{
	char *p = strstr(s, pattern);
	if (p == NULL)
		return false;
	p += strlen(pattern);
	char c;
	sscanf(p, "%lf%c", res, &c);
	switch (c)
	{
	case 'm':
		*res /= 1000;
		break;
	case 'k':
		*res *= 1000;
		break;
	case 'M':
		*res *= 1e6;
		break;
	}
	return true;
}

int main()
{
	char s[1010];
	int n;
	cin >> n;
	cin.get();
	double P, I, U;
	bool gotIUP[3] = { false };
	for (int i = 0; i < n; ++i) {
		cin.getline(s, 1000);
		printf("Problem #%d\n", i + 1);
		int l = strlen(s);
		gotIUP[0] = getpattern(s, l, "I=", &I);
		gotIUP[1] = getpattern(s, l, "U=", &U);
		gotIUP[2] = getpattern(s, l, "P=", &P);
		int idx = 0;
		for (int i = 0; i < 3; ++i)
			if (!gotIUP[i])
				idx = i;
		switch (idx)
		{
		case 0:
			I = P / U;
			printf("I=%.2lfA\n", I);
			break;
		case 1:
			U = P / I;
			printf("U=%.2lfV\n", U);
			break;
		case 2:
			P = U * I;
			printf("P=%.2lfW\n", P);
			break;
		default:
			printf("???\n");
			break;
		}
	}
	return 0;
}