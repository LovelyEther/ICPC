#include <bits/stdc++.h>
using namespace std;

#define N 111

int t, n, a[N], mex[N][N], f[N][N];
bool vis[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[i] = min(a[i], n);
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j ++) {
				memset(vis, 0, sizeof vis);
				for (int k = i; k <= j; k ++) vis[a[k]] = 1;
				int k = 0;
				while (vis[k]) k ++;
				mex[i][j] = k;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j ++) {
				f[i][j] = 1 + mex[i][j];
				for (int k = i; k < j; k ++) {
					f[i][j] = max(f[i][j], f[i][k] + 1 + mex[k+1][j]);
				}
				ans += f[i][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
