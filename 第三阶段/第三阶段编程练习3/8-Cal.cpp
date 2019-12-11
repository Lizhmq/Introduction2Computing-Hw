#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

struct op {
	char c;
	int level;	// 0-2 (+,-), (*,/), -+
	op(char _c, int _level) : c(_c), level(_level) {}
};

void cal(stack<op> &ops, stack<int> &vals)
{
	op cur = ops.top();
	ops.pop();
	switch (cur.c)
	{
	int tmp;
	case '-':
		if (cur.level == 2) {
			vals.top() = -vals.top();
		} else {
			tmp = vals.top();
			vals.pop();
			vals.top() -= tmp;	
		}
		break;
	case '+':
		if (cur.level == 2) {
			
		} else {
			tmp = vals.top();
			vals.pop();
			vals.top() += tmp;	
		}
		break;
	case '*':
		tmp = vals.top();
		vals.pop();
		vals.top() *= tmp;
		break;
	case '/':
		tmp = vals.top();
		vals.pop();
		vals.top() /= tmp;
		break;
	default:
		cout << "????????" << endl;
		break;
	}
}

bool lastOP;

int main()
{
	char s[1010];
	while (cin.getline(s, 1000)) {
		int l = strlen(s);
		stack<op> ops;
		stack<int> vals;
		lastOP = true;
		for (int i = 0; i < l; ++i) {
			if (s[i] == ' ')
				continue;
			if (s[i] == '(') {
				ops.push(op('(', -1));
				lastOP = true;
			} else if (s[i] == ')') {
				while (ops.top().c != '(')
					cal(ops, vals);
				ops.pop();
				lastOP = false;
			} else if (s[i] == '+' || s[i] == '-') {
				if (lastOP) {
					ops.push(op(s[i], 2));
				} else {
					while (!ops.empty() && ops.top().level >= 0)
						cal(ops, vals);
					ops.push(op(s[i], 0));
				}
				lastOP = true;
			} else if (s[i] == '*' || s[i] == '/') {
				while (!ops.empty() && ops.top().level >= 1)
					cal(ops, vals);
				ops.push(op(s[i], 1));
				lastOP = true;
			} else {
				int val = 0;
				while (s[i] <= '9' && s[i] >= '0')
					val = val * 10 + s[i++] - '0';
				i -= 1;
				vals.push(val);
				lastOP = false;
			}
		}
		while (!ops.empty())
			cal(ops, vals);
		cout << vals.top() << endl;
	}
	return 0;
}