#include <bits/stdc++.h>
using namespace std;

int t, n, vis[10101], nxt[10101];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		memset(vis, 0, sizeof vis);
		memset(nxt, 0, sizeof nxt);
		for (int i = 1; i <= n; i ++) if (!vis[i]) {
			int p = 0, j;
			while (1) {
				printf("? %d\n", i); fflush(stdout);
				scanf("%d", &j);
				nxt[p] = j;
				if (vis[j]) break;
				vis[j] = 1;
				p = j;
			}
		}
		printf("!");
		for (int i = 1; i <= n; i ++) printf(" %d", nxt[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}
