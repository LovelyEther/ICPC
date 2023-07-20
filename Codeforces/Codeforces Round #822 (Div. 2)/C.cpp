#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int t, n, vis[N];
char s[N];
vector <int> v[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int i = 1; i < N; i ++) {
		for (int j = i; j < N; j += i) v[j].push_back(i);
	}
	// for (int i = 1; i < N; i ++) sort(v[i].begin(), v[i].end());
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s + 1);
		for (int i = 1; i <= n; i ++) vis[i] = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i] == '0') {
				for (int j = 0; j < v[i].size(); j ++) {
					if (!vis[v[i][j]]) {
						ans += v[i][j]; break;
					}
				}
			}
			else {
				for (int j = 0; j < v[i].size(); j ++) {
					vis[v[i][j]] = 1;
				}
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
