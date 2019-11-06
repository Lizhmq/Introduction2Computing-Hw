#include <iostream>
using namespace std;

int main()
{
	int num[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int minn = num[0];
	for (int i = 1; i < n; ++i)
		minn = min(minn, num[i]);
	for (int i = 0; i < n; ++i)
		if (num[i] == minn) {
			cout << i + 1 << endl;
			break;
		}	
	return 0;
}