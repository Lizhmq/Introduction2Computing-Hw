#include <iostream>
#include <cstdio>
using namespace std;

int num;
int cnt[4];
int coin[4] = {5, 2, 1};

void money(int left, int k)
{
	if (k == 3) {
		if (left == 0)
			printf("%03d%12d%12d%12d\n", ++num, cnt[2], cnt[1], cnt[0]);;
		return;
	}
	int prob = left / coin[k];
	for (int i = 0; i <= prob; ++i) {
		cnt[k] = i;
		money(left - coin[k] * i, k + 1);
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	money(n, 0);
	return 0;
}