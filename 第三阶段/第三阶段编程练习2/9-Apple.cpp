#include <iostream>
#include <cstring>
using namespace std;

int func(int apple, int plate)
{
	if (apple == 0)
		return 1;
	if (plate == 0)
		return 0;
	if (plate > apple)
		return func(apple, apple);
	return func(apple - plate, plate) + func(apple, plate - 1);
}

int main()
{
	int cases, apple, plate;
	cin >> cases;
	while (cases--) {
		cin >> apple >> plate;
		cout << func(apple, plate) << endl;
	}
	return 0;
}