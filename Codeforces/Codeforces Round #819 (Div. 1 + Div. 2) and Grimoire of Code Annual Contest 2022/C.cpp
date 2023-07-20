#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, vis[N];
char s[N];
stack <int> st;
vector <int> v[N];

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) if (!vis[v[x][i]]) dfs(v[x][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s + 1);
		for (int i = 1; i <= 2 * n; i ++) v[i].clear(), vis[i] = 0;
		for (int i = 1; i <= 2 * n; i ++) {
			if (s[i] == '(') {
				st.push(i);
				if (i > 1 && s[i-1] == ')') {
					v[i-1].push_back(i);
					v[i].push_back(i - 1);
				}
			}
			else {
				int j = st.top();
				st.pop();
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i ++) if (!vis[i]) cnt ++, dfs(i);
		printf("%d\n", cnt);
	}
	return 0;
}
