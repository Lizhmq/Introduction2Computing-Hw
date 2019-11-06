#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int res = 0, tmp;
	while (n--) {
		cin >> tmp;
		res ^= tmp;
	}
	cout << res << endl;
	return 0;
}