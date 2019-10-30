#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct STU {
	int id;
	int chinese;
	int math;
	int sum;
} stus[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> stus[i].id >> stus[i].chinese >> stus[i].math;
		stus[i].sum = stus[i].chinese + stus[i].math;
	}
	for (int i = 0; i < 3; ++i)		// execute bubble sort three times
		for (int j = n - i - 2; j >= 0; --j)
			if (stus[j].sum < stus[j + 1].sum)
				swap(stus[j], stus[j + 1]);
	for (int i = 0; i < 3; ++i)
		cout << stus[i].id << " " << stus[i].sum << endl;
	return 0;
}