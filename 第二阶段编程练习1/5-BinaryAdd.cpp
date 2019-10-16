#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	char num1[110], num2[110];
	int num3[110];
	cin >> n;
	while (n--) {
		memset(num1, '0', sizeof(num1));
		memset(num2, '0', sizeof(num2));
		memset(num3, 0, sizeof(num3));
		cin >> num1 >> num2;
		int l1 = strlen(num1);
		int l2 = strlen(num2);
		num1[l1] = num2[l2] = '0';
		reverse(num1, num1 + l1);
		reverse(num2, num2 + l2);
		for (int i = 0; i < max(l1, l2); ++i) {
			int t = num1[i] - '0' + num2[i] - '0';
			num3[i] += t;
			num3[i + 1] += num3[i] / 2;
			num3[i] %= 2;
		}
		int i = max(l1, l2);
		while (i >= 1 && num3[i] == 0)
			i--;
		while (i >= 0)
			cout << num3[i--];
		cout << endl;
	}
	return 0;
}