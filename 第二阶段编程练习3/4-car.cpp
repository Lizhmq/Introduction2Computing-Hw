#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 16; ++i) {
		
		bool S1 = i & 1, S2 = (i >> 1) & 1;
		bool S3 = (i >> 2) & 1, S4 = (i >> 3) & 1;
		if (S1 + S2 + S3 + S4 != 1)
			continue;
		bool A = S2, B = S4, C = !S3, D = !S4;
		if (A + B + C + D == 1) {
			bool car[4] = {S1, S2, S3, S4};
			bool expert[4] = {A, B, C, D};
			for (int i = 0; i < 4; ++i)
				if (car[i])
					cout << i + 1 << endl;
			for (int i = 0; i < 4; ++i)
				if (expert[i])
					cout << char('A' + i) << endl;
			goto end;
		}
	}
end:
	return 0;
}