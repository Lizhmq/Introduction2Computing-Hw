#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	int id, num;
	char cls;
	double money;
	double peoples[3] = {0.}, classes[3] = {0.};
	while (cin >> id) {
		cin >> num;
		while (num--) {
			cin >> cls >> money;
			classes[cls - 'A'] += money;
			peoples[id - 1] += money;
		}
	}
	for (int i = 0; i < 3; ++i)
		cout << i + 1 << " " << setprecision(2)
			<< setiosflags(ios::fixed) << peoples[i] << endl;
	for (int i = 0; i < 3; ++i)
		cout << char('A' + i) << " " << setprecision(2)
			<< setiosflags(ios::fixed) << classes[i] << endl;
	return 0;
}