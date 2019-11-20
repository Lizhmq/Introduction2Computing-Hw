#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Pos {
	char c;
	int idx;
	Pos(char cc, int iidx) : c(cc), idx(iidx) {}
};

int main()
{
	stack<Pos> st;
	char s[110];
	cin >> s;
	int l = strlen(s);
	char boy = s[0];
	for (int i = 0; i < l; ++i) {
		if (st.empty() || s[i] == boy)
			st.push(Pos(s[i], i));
		else {
			cout << st.top().idx << ' ' << i << endl;
			st.pop();
		}
	}
	return 0;
}