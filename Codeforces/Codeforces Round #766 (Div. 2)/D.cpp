#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int n, ans, vis[N], org[N], f[N];
vector <int> v[N];

void dfs(int x) {
	vis[x] = 1;
	int rlt = 0;
	if (org[x]) rlt = x;
	for (int y = 2 * x; y < N; y += x) if (!vis[y]) {
		dfs(y);
	}
	for (int y = 2 * x; y < N; y += x) {
		if (f[y]) rlt = __gcd(rlt, f[y]);
	}
	if (!org[x] && rlt == x) ans ++;
	f[x] = rlt;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		org[x] = 1;
	}
	for (int i = 1; i < N; i ++) {
		for (int j = i * 2; j < N; j += i) v[i].push_back(j);
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
