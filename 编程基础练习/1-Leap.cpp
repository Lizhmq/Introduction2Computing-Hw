#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << (((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) ? "Y" : "N") << endl;
	return 0;
}