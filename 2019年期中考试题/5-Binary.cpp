#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int nums1[200], nums2[200];
	int idxs1[200], idxs2[200];
	int idx1 = 0, idx2 = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> nums1[i];
	for (int i = 0; i < n; ++i)
		cin >> nums2[i];
	for (int i = 0; i < n; ++i)
		if (nums1[i] == 1)
			idxs1[idx1++] = i;
	for (int i = 0; i < n; ++i)
		if (nums2[i] == 1)
			idxs2[idx2++] = i;
	if (idx1 != idx2)
		cout << -1 << endl;
	else {
		int res = 0;
		for (int i = 0; i < idx1; ++i)
			res += abs(idxs1[i] - idxs2[i]);
		cout << res << endl;
	}
	return 0;
}