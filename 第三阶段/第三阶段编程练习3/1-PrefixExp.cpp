#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

double func()
{
	char c[100];
	cin >> c;
	switch (c[0]) {
		case '*': return func() * func();
		case '+': return func() + func();
		case '-': return func() - func();
		case '/': return func() / func();
		default:
			return atof(c);
	}
}

int main()
{
	printf("%f\n", func());
	return 0;
}