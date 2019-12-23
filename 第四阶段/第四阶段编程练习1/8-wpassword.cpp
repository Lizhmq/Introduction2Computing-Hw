#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	char s[110];
	char s1[100], s2[100], s3[100];
	int a, b, c;
	while (cin >> a >> b >> c && a) {
		cin.get();
		cin.getline(s, 100);
		int idx1 = 0, idx2 = 0, idx3 = 0;
		int l = strlen(s);
		for (int i = 0; i < l; ++i) {
			if (s[i] >= 'a' && s[i] <= 'i') {
				s1[idx1++] = s[i];
			} else if (s[i] >= 'j' && s[i] <= 'r') {
				s2[idx2++] = s[i];
			} else {
				s3[idx3++] = s[i];
			}
		}
		int idx21 = 0, idx22 = 0, idx23 = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] >= 'a' && s[i] <= 'i') {
				s[i] = s1[(idx21++ - a + 100000 * idx1) % idx1];
			} else if (s[i] >= 'j' && s[i] <= 'r') {
				s[i] = s2[(idx22++ - b + 100000 * idx2) % idx2];
			} else {
				s[i] = s3[(idx23++ - c + 100000 * idx3) % idx3];
			}			
		}
		cout << s << endl;
	}
	return 0;
}