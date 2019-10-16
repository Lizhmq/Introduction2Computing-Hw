#include <iostream>
using namespace std;

int main()
{
	char c;
	int cnt[3] = {0};
	while ((c = cin.get()) != '\n') {
		if (c >= 'A' && c <= 'Z')
			cnt[0]++;
		else if (c >= 'a' && c <= 'z')
			cnt[1]++;
		else if (c >= '0' && c <= '9')
			cnt[2]++;
	}
	cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << endl;
	return 0;
}