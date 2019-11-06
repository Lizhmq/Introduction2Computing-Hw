#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159

int main()
{
	double r, h;
	cin >> r >> h;
	double area = 2 * PI * r * (r + h);
	cout << "Area = " << setprecision(3)
			<< setiosflags(ios::fixed) << area << endl;
	return 0;
}