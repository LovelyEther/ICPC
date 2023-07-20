#include <bits/stdc++.h>
using namespace std;

#define N 505

int di[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[] = {1, 0, -1, 1, 0, -1, 1, -1};

int t, n, m;
char s[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
		int ans = 0, good = false;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (s[i][j] == '1') {
					ans ++; continue;
				}
				for (int k = 0; k < 8; k ++) {
					int ii = i + di[k], jj = j + dj[k];
					if (ii <= 0 || ii > n || jj <= 0 || jj > m) continue;
					if (s[ii][jj] == '0') good = true;
				}
			}
		}
		if (good) {}
		else if (ans < n * m) ans --;
		else ans -= 2;
		printf("%d\n", ans);
	}
	return 0;
}
