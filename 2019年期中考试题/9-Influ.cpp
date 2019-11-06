#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> G[100010];
int waited[100010];
bool isvis[100010];
int n, m, u, v, s;
int ans;
queue<int> que;

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d", &s);
	memset(isvis, 0, sizeof(isvis));
	ans = 0;
	que.push(s);
	isvis[s] = true;                                               
	while (!que.empty()){
		++ans;
		int cnt = 0;
		while(!que.empty()){
			u = que.front();
			que.pop();
			for(int i = 0; i < G[u].size(); i++){
				v = G[u][i];
				if(!isvis[v]){
					isvis[v] = true;
					waited[cnt] = v;
					++cnt;
				}
			}
		}
		for(int i = 0; i < cnt; i++)
			que.push(waited[i]);
	}
	printf("%d", ans);
	return 0;
}
