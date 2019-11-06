#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double n;
	while (cin >> n) {
		double root = 1.0, prev = 0;
		int counter = 0;
		while (abs(root - prev) > 1e-6) {
			prev = root;
			root = (root + n / root) / 2;
			counter++;
		}
		cout << counter << ' ' << setprecision(2)
			<< setiosflags(ios::fixed) << root << endl;
	}
	return 0;
}