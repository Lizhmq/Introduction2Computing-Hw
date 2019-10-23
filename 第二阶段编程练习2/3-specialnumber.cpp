#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int changebase(char nums[], int base, int num)
{
	int i = 0;
	while (num) {
		nums[i++] = num % base + '0';
		num /= base;
	}
	return i;
}

int main()
{
	char num1[10], num2[10];
	int i;
	for (i = 0; i < 1000; ++i) {
		int a = changebase(num1, 7, i);
		int b = changebase(num2, 9, i);
		if (a == b && a == 3 && num1[0] == num2[2] && num1[1] == num2[1] && num1[2] == num2[0])
			break;
	}
	int n;
	cin >> n;
	memset(num1, 0, sizeof(num1));
	n = n == 1 ? 10 : n == 2 ? 7 : 9;
	changebase(num1, n, i);
	reverse(num1, num1 + 3);
	cout << num1 << endl;
	return 0;
}