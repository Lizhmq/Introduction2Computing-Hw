#### 冒泡排序

```c++
#include <iostream>
using namespace std;

int main() {
	int n, a[1000];
	int i = 0, j = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
		for (j = 1; j < n - i; j++) {
			if (a[j - 1] > a[j]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	for (i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
```

#### 分数加法

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sumn = 0, sumd = 1;
	while (n--) {
		int num, deno;
		char slash;
		cin >> num >> slash >> deno;
		sumn = sumn * deno + num * sumd;
		sumd = sumd * deno;
	}
	int a = sumd, b = sumn, c;
	while (a != 0) {
		c = a;
		a = b % a;
		b = c;
	}
	int gcd = b;
	sumd /= gcd;
	sumn /= gcd;
	if (sumd > 1)
		cout << sumn << '/' << sumd << endl;
	else
		cout << sumn << endl;
	return 0;
}
```

#### 大整数加法

```cpp
#include <iostream>
#include <cstring>
using namespace std;

char str1[201], str2[201];
int a1[200] = {0}, a2[201] = {0};

int main() {
	int i, n, len1, len2;
	cin >> n;
	while (n--) {
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		cin >> str1 >> str2;
		len1 = strlen(str1);
		len2 = strlen(str2);
		for (i = 0; i < len1; i++)
			a1[i] = str1[len1 - 1 - i] - '0';
		for (i = 0; i < len2; i++)
			a2[i] = str2[len2 - 1 - i] - '0';
		for (i = 0; i < 200; i++) {
			a2[i] += a1[i];
			if (a2[i] >= 10) {
				a2[i] -= 10;
				a2[i + 1]++;
			}
		}
		for (i = 200; i >= 0; i--)
			if (a2[i] != 0)
				break;
		if (i == -1)
			cout << 0;
		else
			for (; i >= 0; i--)
				cout << a2[i];
		cout << endl;
	}
	return 0;
}
```

