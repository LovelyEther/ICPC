#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int t, n, C, a[N];
int T, vis[N], cnt[N];

bool good() {
	if (a[1] != 1) return 0;
	T ++;
	for (int i = 1; i <= n; i ++) vis[a[i]] = T;
	for (int i = 1; i <= C; i ++) cnt[i] = cnt[i-1] + (vis[i] == T);
	for (int x = 2; x <= C; x ++) if (vis[x] != T) {
		for (int i = 1; i <= n; i ++) {
			if (1ll * a[i] * x > C) break;
			int st = a[i] * x, en = min(C, st + a[i] - 1);
			if (cnt[en] - cnt[st-1] > 0) return 0;
		}
	}
	return 1;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &C);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		if (good()) puts("Yes");
		else puts("No");
	}
	return 0;
}
