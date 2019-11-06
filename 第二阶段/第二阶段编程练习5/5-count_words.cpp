#include <iostream>
#include <cstring>
using namespace std;

char sent[10010];
char words[100][100];
int wordcnt[1000];
int wordidx = 0;
const char puncs[20] = ",. ;:?!-()~";

bool punc(char c)
{
	int l = strlen(puncs);
	for (int i = 0; i < l; ++i)
		if (puncs[i] == c)
			return true;
	return false;
}

int extract(char sent[], int start, int maxlen)
{
	char curword[100];
	int idx = 0;
	while (start < maxlen && punc(sent[start]))		// find start of word
		start++;
	if (start == maxlen)
		return maxlen;
	while (start < maxlen && !punc(sent[start]))		// find end of word
		curword[idx++] = sent[start++];
	curword[idx] = '\0';
	bool same = false;					// insert word to word list
	for (int i = 0; i < wordidx; ++i)
		if (strcmp(words[i], curword) == 0) {
			wordcnt[i]++;
			same = true;
			break;
		}
	if (!same) {
		strcpy(words[wordidx], curword);
		wordcnt[wordidx] += 1;
		wordidx++;
	}
	return start;
}

int main()
{
	cin.getline(sent, 10000);
	int l = strlen(sent);
	int i = 0;
	while (i < l)
		i = extract(sent, i, l);			// extract a word and update index i
	for (int i = 0; i < wordidx; ++i)
		cout << words[i] << ' ' << wordcnt[i] << endl;
	return 0;
}