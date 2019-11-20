#include <iostream>
#include <cstring>
using namespace std;

char S[520], T[200][520];
int dp[520][520];
int dist[520];

int similar(char s[], char t[])
{
	int l1 = strlen(s), l2 = strlen(t);
	for (int i = 0; i < l1; ++i)
		dp[i][0] = i;
	for (int j = 0; j < l2; ++j)
		dp[0][j] = j;
	for (int i = 0; i < l1; ++i)
		for (int j = 0; j < l2; ++j)
			dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] : min(dp[i + 1][j], dp[i][j + 1]) + 1;
	return dp[l1][l2];
}

int main()
{
	int n;
	cin >> S >> n;
	int mindist = 1000;
	for (int i = 0; i < n; ++i) {
		cin >> T[i];
		dist[i] = similar(S, T[i]);
		mindist = min(mindist, dist[i]);
	}
	for (int i = 0; i < n; ++i)
		if (dist[i] == mindist)
			cout << T[i] << endl;
	return 0;
}