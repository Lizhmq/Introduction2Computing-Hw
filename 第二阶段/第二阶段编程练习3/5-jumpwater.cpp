#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

/*
 * 常规做法参考四大湖
 * 这里给了一个非常规做法，不要求掌握
 */

int main()
{
	int ranks[] = {1, 2, 3, 4, 5};
	bool have_next = true;
	while (have_next) {
		int A = (ranks[1] == 2) + (ranks[0] == 3);
		int B = (ranks[1] == 2) + (ranks[4] == 4);
		int C = (ranks[2] == 1) + (ranks[3] == 2);
		int D = (ranks[2] == 5) + (ranks[3] == 3);
		int E = (ranks[4] == 4) + (ranks[0] == 1);
		int v[] = {A, B, C, D, E};
		sort(v, v + 5);
		if (v[0] == 1 && v[4] == 1) {
			for (int i = 0; i < 5; ++i)
				cout << ranks[i] << endl;
			goto end;
		}
		have_next = next_permutation(ranks, ranks + 5);
	}
end:
	return 0;
}