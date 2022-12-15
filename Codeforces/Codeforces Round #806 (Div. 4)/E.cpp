#include <bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, vis[N][N];
char s[N][N];

int idx(int i, int j) {
	return s[i][j] - '0';
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) scanf("%s", s[i]);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) vis[i][j] = 0;
		}
		int ans = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) if (!vis[i][j]) {
				int sum = idx(i, j) + idx(j, n - 1 - i) + idx(n - 1 - i, n - 1 - j) + idx(n - 1 - j, i);
				vis[i][j] = 1;
				vis[j][n-1-i] = 1;
				vis[n-1-i][n-1-j] = 1;
				vis[n-1-j][i] = 1;
				ans += min(sum, 4 - sum);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
