#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool leap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
	int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, d = 1;		// 0-6 for Sun-Sat
	cin >> year >> month;
	for (int i = 1900; i < year; ++i)
		if (leap(i))
			d += 366;
		else
			d += 365;
	if (leap(year))
		months[2] = 29;
	for (int i = 1; i < month; ++i)
		d += months[i];
	d %= 7;
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	for (int i = 0; i < d; ++i)
		printf("    ");
	for (int i = 1; i <= months[month]; ++i) {
		printf("%4d", i);
		if ((d + 1) % 7 == 0)
			printf("\n");
		d += 1;
	}
	return 0;
}