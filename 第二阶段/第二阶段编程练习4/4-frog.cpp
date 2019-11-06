#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int h, u, d;
	cin >> h >> u >> d;
	int res = 0, curh = 0;
	while (curh < h) {
		res++;
		curh += u;
		if (curh >= h)
			break;
		curh -= d;
	}
	cout << res << endl;
	return 0;
}