#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
} intervals[100000];

bool cmp(const Interval &a, const Interval &b)
{
	return a.end < b.end || a.end == b.end && a.start < b.start;
}

int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> intervals[i].start >> intervals[i].end;
	sort(intervals, intervals + n, cmp);
	int curend = 0, res = 0;
	for (int i = 0; i < n; ++i) {
		if (intervals[i].start < curend)
			continue;
		res++;
		curend = intervals[i].end;
	}
	cout << res << endl;
	return 0;
}