#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int cnt = 0;
	for (int i = 1; i * i <= 150; ++i) {
		if (cnt > 0)
			cout << ' ';
		cout << 'N' << i * i;
		cnt++;
	}
	cout << endl << cnt << endl;
	return 0;
}