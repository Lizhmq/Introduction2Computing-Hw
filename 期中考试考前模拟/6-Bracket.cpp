#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int fake_stack[510];
int stack_idx = 0;	

void push(int val) { fake_stack[stack_idx++] = val; }
int pop() { return fake_stack[--stack_idx]; }
int top() { return fake_stack[stack_idx - 1]; }

struct Pair {
	int start, end;
} pairs[500];
int pair_idx = 0;

bool cmp(const Pair &a, const Pair &b)
{
	if (a.end - a.start < b.end - b.start)
		return true;
	if (a.end - a.start > b.end - b.start)
		return false;
	return a.start < b.start;
}

int main()
{
	char s[510];
	cin.get(s, 500);
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		if (s[i] == '(')
			push(i);
		else if (s[i] == ')') {
			if (stack_idx == 0) {
				cout << "mismatch" << endl;
				goto end;
			}
			int start = pop();
			pairs[pair_idx].start = start + 1;
			pairs[pair_idx].end = i + 1;
			pair_idx++;
		}
	}
	if (stack_idx > 0) {
		cout << "mismatch" << endl;
		goto end;
	}
	if (pair_idx == 0) {
		cout << "0,0" << endl;
		goto end;
	}
	sort(pairs, pairs + pair_idx, cmp);
	for (int i = 0; i < pair_idx; ++i)
		cout << pairs[i].start << ',' << pairs[i].end << endl;
end:
	return 0;
}