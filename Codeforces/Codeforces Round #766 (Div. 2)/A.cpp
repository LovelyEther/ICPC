#include <bits/stdc++.h>
using namespace std;

#define N 55

int t, n, m, r, c;
char s[N][N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &n, &m, &r, &c);
		for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
		if (s[r][c] == 'B') {
			puts("0"); continue;
		}
		bool one = false;
		for (int j = 1; j <= m; j ++) if (s[r][j] == 'B') one = true;
		for (int i = 1; i <= n; i ++) if (s[i][c] == 'B') one = true;
		if (one) {
			puts("1"); continue;
		}
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (s[i][j] == 'B') one = true;
		if (one) puts("2");
		else puts("-1");
	}
	return 0;
}
