#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	double res = 1, tmp = 1;
	int i = 1;
	while (tmp > 1e-7) {
		tmp /= i++;
		res += tmp;
	}
	cout << setprecision(6)	<< setiosflags(ios::fixed) << res << endl;
	return 0;
}