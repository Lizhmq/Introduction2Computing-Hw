#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char a[100] = {0};

int matched(int l, int r) //前终止点，后开始点
{
	int cnt = 1, ans = 0;
	for (int i = r - 1; i >= l; i--) {
		if (a[i] == ')')
			cnt++;
		else if (a[i] == '(')
			cnt--;
		if (cnt == 0) {
			ans = i;
			break;
		}
	}
	return ans;
}

int compute(int l, int r)
{
	for (int i = r; i >= l; i--) {
		if (a[i] == ')')
			i = matched(l, i);
		if (a[i] == '+')
			return compute(i + 1, r) + compute(l, i - 1);
		if (a[i] == '-')
			return compute(l, i - 1) - compute(i + 1, r);
	}
	for (int i = r; i >= l; i--) {
		if (a[i] == ')')
			i = matched(l, i);
		if (a[i] == '*')
			return compute(i + 1, r) * compute(l, i - 1);
		if (a[i] == '/')
			return compute(l, i - 1) / compute(i + 1, r);
	}
	//到此处还没返回，说明没有运算符，只有括号和数字
	if (a[r] == ')')
		return compute(l + 1, r - 1);
	if (a[r] >= '0' && a[r] <= '9') {
		int ans = 0, j = 0;
		for (int i = r; i >= l; i--, j++)
			ans += pow(10.0, (double)j) * (a[i] - '0');
		return ans;
	}
	return 0;
}

int main()
{
	while (cin.getline(a, 100)) {
		int x = strlen(a);
		cout << compute(0, x - 1) << endl;
	}
	return 0;
}