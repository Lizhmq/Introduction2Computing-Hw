#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int n, t[20];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	sort(t, t + n);			// 排队 -> 排序
	for (int i = 0; i < n; ++i)	// 8点前到达的人可以看作八点到达
		if (t[i] < 60)
			t[i] = 60;
	int T = 60, res = 0;
	for (int i = 0; i < n; ++i) {	// T维护当前病人看完病的时间
		T = max(T, t[i]) + 10;
		if (T > 180)
			break;
		res++;
	}
	cout << res << endl;
	return 0;
}