#include <iostream>
#include <cstring>
using namespace std;

bool leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 
		|| year % 400 == 0;
}

int weekday(int year, int month, int day)
{
	int start = 5;		// 0-6 for 周一-日
	for (int i = 2000; i < year; ++i)
		start += leap(i) ? 366 : 365;
	int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (leap(year))
		months[2] = 29;
	for (int i = 1; i < month; ++i)
		start += months[i];
	start += day - 1;
	return start % 7;
}

bool restrict(int DAY, char end)
{
	return DAY == 0 && (end == '1' || end == '6')
		|| DAY == 1 && (end == '2' || end == '7')
		|| DAY == 2 && (end == '3' || end == '8')
		|| DAY == 3 && (end == '4' || end == '9')
		|| DAY == 4 && (end == '5' || end == '0' || isalpha(end));
}

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int year, month, day;
		char tmp;
		char id[10];
		cin >> year >> tmp >> month >> tmp >> day;
		cin >> id;
		int DAY = weekday(year, month, day);
		cout << (restrict(DAY, id[5]) ? "yes" : "no") << endl;
	}
	return 0;
}