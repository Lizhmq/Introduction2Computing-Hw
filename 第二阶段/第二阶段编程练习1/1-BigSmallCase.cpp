#include <iostream>
using namespace std;

int main()
{
	char c;
	cin >> c;
	if (c <= 'z' && c >= 'a')
		cout << "lower case" << endl;
	else if (c <= 'Z' && c >= 'A')
		cout << "upper case" << endl;
	else
		cout << "invalid input" << endl;
	return 0;
}