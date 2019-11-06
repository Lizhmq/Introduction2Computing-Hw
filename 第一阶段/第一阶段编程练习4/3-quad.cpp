#include <iostream>
using namespace std;


bool judge(int x[], int y[])
{
	for (int i = 0; i < 4; ++i) {
		int v1_x = x[(i + 1) % 4] - x[i];	// vector AB
		int v1_y = y[(i + 1) % 4] - y[i];	
		int v2_x = x[(i + 2) % 4] - x[(i + 1) % 4];	// vector BC
		int v2_y = y[(i + 2) % 4] - y[(i + 1) % 4];
		int v3_x = x[(i + 3) % 4] - x[(i + 1) % 4];	// vector BD
		int v3_y = y[(i + 3) % 4] - y[(i + 1) % 4];
		int prod1 = v1_x * v2_y - v1_y * v2_x;		// AB x BC
		int prod2 = v1_x * v3_y - v1_y * v3_x;		// AB x BD
		if (1.0 * prod1 * prod2 <= 0)		// different sign
			return false;
	}
	return true;
}

int main()
{
	int x[4], y[4];
	while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3])
		cout << (judge(x, y) ? "yes" : "no") << endl;
	return 0;
}