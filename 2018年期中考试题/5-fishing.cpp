#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	int ms[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> year >> month >> day;
	int d = 0;
	for (int i = 1990; i < year; ++i)
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			d += 366;
		else
			d += 365;
	for (int i = 1; i < month; ++i)
		d += ms[i];
	if (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		d += 1;
	d += day - 1;
	d %= 5;
	cout << (d < 3 ? "fishing" : "sleeping") << endl; 
	return 0;
}
