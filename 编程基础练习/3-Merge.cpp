#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int a[10], b[10], c[20];
	for (int i = 0; i < 10; ++i)
		cin >> a[i];
	for (int i = 0; i < 10; ++i)
		cin >> b[i];
	int i = 0, j = 0, k = 0;
	while (i < 10 && j < 10) {
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < 10)
		c[k++] = a[i++];
	while (j < 10)
		c[k++] = b[j++];
	cout << c[0];
	for (int i = 1; i < 20; ++i)
		cout << ' ' << c[i];
	cout << endl;
	return 0;
}