#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int parentlist1[20], idx1 = 0;
	int parentlist2[20], idx2 = 0;
	int a, b;
	cin >> a >> b;
	while (a) {
		parentlist1[idx1++] = a;
		a /= 2;
	}
	while (b) {
		parentlist2[idx2++] = b;
		b /= 2;
	}
	reverse(parentlist1, parentlist1 + idx1);
	reverse(parentlist2, parentlist2 + idx2);
	int i;
	for (i = 0; i < min(idx1, idx2); ++i)
		if (parentlist1[i] != parentlist2[i])
			break;
	cout << parentlist1[i - 1] << endl;
	return 0;
}
