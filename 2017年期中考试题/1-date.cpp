#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << ((n == 1 || n == 3 || n == 5) ? "NO" : "YES") << endl;
	return 0;
}