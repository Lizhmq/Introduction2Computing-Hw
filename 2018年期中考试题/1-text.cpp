#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n, tmp;
	double res = 0;
	cin >> n;
	while (n--) {
		cin >> tmp;
		res += (tmp + 69) / 70;
	}
	printf("%.1f\n", res / 10);
	return 0;
}