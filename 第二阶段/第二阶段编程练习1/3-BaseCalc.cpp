#include <iostream>
#include <algorithm>
using namespace std;

char chs[] = "0123456789abcdef";

int convert(char num[], int base)
{
	int res = 0, i = 0;
	while (num[i] != '\0') {
		char c = num[i];
		int tmp = (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
		res = res * base + tmp;
		i++;
	}
	return res;
}

int main()
{
	char num1[1000], num2[1000];
	int base1, base2, base3;
	cin >> base1 >> num1;
	cin >> base2 >> num2;
	cin >> base3;
	int sum = convert(num1, base1) + convert(num2, base2);
	int i = 0;
	while (sum) {
		num1[i++] = chs[sum % base3];
		sum /= base3;
	}
	num1[i] = '\0';
	reverse(num1, num1 + i);
	cout << num1 << endl;
	return 0;
}