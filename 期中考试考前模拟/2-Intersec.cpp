#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
	int num1[210], num2[210], num3[210];
	int idx1 = 0, idx2 = 0, idx3 = 0;
	char c;
	while (true) {
		cin >> num1[idx1++];
		cin.get(c);
		if (c == '\n')
			break;
	}
	while (true) {
		cin >> num2[idx2++];
		cin.get(c);
		if (c == '\n')
			break;
	}
	sort(num1, num1 + idx1);
	sort(num2, num2 + idx2);
	for (int i = 0; i < idx1; ++i)
		for (int j = 0; j < idx2; ++j)
			if (num1[i] == num2[j])
				num3[idx3++] = num1[i];
	if (idx3 == 0)
		cout << "NULL" << endl;
	else {
		sort(num3, num3 + idx3);
		int *end = unique(num3, num3 + idx3);
		for (int *p = num3; p != end; ++p) {
			if (p + 1 == end)
				cout << *p << endl;
			else
				cout << *p << ',';
		}
	}
	return 0;
}