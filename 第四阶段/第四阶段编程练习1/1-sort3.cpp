#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	char s[100];
	scanf("%s", s);
	int l = strlen(s);
	bool flag = false;
	for (int i = 0; i < l; ++i)
		if (s[i] == '.')
			flag = true;
	int integer[3] = { 0 };
	double d[3] = { 0 };
	if (!flag)
		sscanf(s, "%d,%d,%d", integer, integer + 1, integer + 2);
	else
		sscanf(s, "%lf,%lf,%lf", d, d + 1, d + 2);
	sort(integer, integer + 3);
	sort(d, d + 3);
	if (!flag)
		printf("%d,%d,%d\n", integer[0], integer[1], integer[2]);
	else
		for (int i = 0; i < 3; ++i)
			if (abs(round(d[i]) - d[i]) < 1e-8)
				printf("%.0f%c", d[i], "\n,"[i < 2]);
			else
				printf("%.2f%c", d[i], "\n,"[i < 2]);
	return 0;
}