#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool win(int a, int b)
{
	if (a == 0 || b == 0)
		return false;
	if (a < b)
		swap(a, b);
	if (a / b >= 2)
		return true;
	return !win(b, a - b);
}

int main()
{
	int a, b;
	while (cin >> a >> b && a)
		cout << (win(a, b) ? "win" : "lose") << endl;
	return 0;
}