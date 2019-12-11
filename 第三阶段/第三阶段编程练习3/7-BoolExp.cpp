#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

struct op {
	char c;
	int level;	// 0-2 | & !
	op(char _c, int _level) : c(_c), level(_level) {}
};

void cal(stack<op> &ops, stack<int> &vals)
{
	op cur = ops.top();
	ops.pop();
	switch (cur.c)
	{
	bool tmp;
	case '!':
		vals.top() = !vals.top();
		break;
	case '|':
		tmp = vals.top();
		vals.pop();
		vals.top() |= tmp;
		break;
	case '&':
		tmp = vals.top();
		vals.pop();
		vals.top() &= tmp;
		break;
	default:
		cout << "????????" << endl;
		break;
	}
}

int main()
{
	char s[1010];
	while (cin.getline(s, 1000)) {
		int l = strlen(s);
		stack<op> ops;
		stack<int> vals;
		for (int i = 0; i < l; ++i) {
			if (s[i] == ' ')
				continue;
			if (s[i] == '(') {
				ops.push(op('(', -1));
			} else if (s[i] == ')') {
				while (ops.top().c != '(')
					cal(ops, vals);
				ops.pop();
			} else if (s[i] == '|') {
				while (!ops.empty() && ops.top().level > 0)
					cal(ops, vals);
				ops.push(op(s[i], 0));
			} else if (s[i] == '&') {
				while (!ops.empty() && ops.top().level > 1)
					cal(ops, vals);
				ops.push(op(s[i], 1));
			} else if (s[i] == '!') {
				while (!ops.empty() && ops.top().level > 2)
					cal(ops, vals);
				ops.push(op(s[i], 2));
			} else {
				vals.push(s[i] == 'V');
			}
		}
		while (!ops.empty())
			cal(ops, vals);
		cout << (vals.top() ? "V" : "F") << endl;
	}
	return 0;
}