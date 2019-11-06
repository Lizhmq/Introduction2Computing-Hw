#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	for (int py = 1; py <= 4; ++py)
		for (int dt = 1; dt <= 4; ++dt)
			for (int tai = 1; tai <= 4; ++tai)
				for (int hz = 1; hz <= 4; ++hz) {
					int tmp[4] = {py, dt, tai, hz};
					sort(tmp, tmp + 4);
					bool flag = false;
					for (int t = 0; t < 4; ++t)
						if (tmp[t] != t + 1) {
							flag = true;
							break;
						}
					if (flag)
						continue;
					int A = (dt == 1) + (hz == 4) + (py == 3);
					int B = (hz == 1) + (dt == 4) + (py == 2) + (tai == 3);
					int C = (hz == 4) + (dt == 3);
					int D = (py == 1) + (tai == 4) + (hz == 2) + (dt == 3);
					if (A == 1 && B == 1 && C == 1 && D == 1) {
						cout << py << endl << dt << endl;
						cout << tai << endl << hz << endl;
						goto end;
					}
				}
end:
	return 0;
}