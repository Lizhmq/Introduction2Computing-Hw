#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main()
{
	int a, b;
	char c;
	cin >> a >> c >> b;
	cout << a * b / gcd(a, b) << endl;
	return 0;
}