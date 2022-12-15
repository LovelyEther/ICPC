#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, m, dp[N], leafs;
vector <int> v[N];
long long cnt[N];

void dfs(int x, int p = 0) {
	dp[x] = dp[p] + 1;
	bool leaf = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		if (v[x][i] != p) dfs(v[x][i], x), leaf = 0;
	}
	if (leaf) {
		cnt[dp[x]] ++;
		leafs ++;
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) v[i].clear(), dp[i] = cnt[i] = 0;
		for (int i = 1; i < n; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		leafs = 0;
		dfs(1);
		int mx_dp = 0;
		for (int i = 1; i <= n; i ++) mx_dp = max(mx_dp, dp[i]);
		for (int i = 1; i <= mx_dp; i ++) cnt[i] += cnt[i-1];
		for (int i = 1; i <= mx_dp; i ++) cnt[i] += cnt[i-1];
		long long ans = 0;
		for (int i = 1, x = 0, y = 0; i <= m; i ++) {
			scanf("%d", &x);
			if (x - y >= mx_dp) {
				ans += cnt[mx_dp] + 1ll * (x - y - mx_dp) * leafs;
			}
			else {
				ans += cnt[x - y];
			}
			y = x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
