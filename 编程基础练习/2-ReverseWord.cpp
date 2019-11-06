#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findend(char s[], int start, int maxlen)
{
	int i = start;
	while (i < maxlen && s[i] != ' ')
		i++;
	return i;
}

int main()
{
	char s[1010];
	cin.get(s, 110);
	int l = strlen(s);
	int i = 0;
	while (i < l) {
		int j = findend(s, i, l);	// find a word [i, j)
		reverse(s + i, s + j);		// reverse this word
		i = j;
		while (i < l && s[i] == ' ')
			i++;
	}			// reverse the sentence
	cout << s << endl;
	return 0;
}