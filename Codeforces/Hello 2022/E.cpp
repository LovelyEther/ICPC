#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

#define N 200200

int t, n, m, a[N], b[N], cnt[N], allows[N], f[N];
long long sum[N];
char s[N];

int c[N];
int mx[N][22];

int rmq(int l, int r) {
	if (r < 0 || l > n) return -inf;
	int d = 31 - __builtin_clz(r - l + 1);
	return max(mx[l][d], mx[r-(1<<d)+1][d]);
}

int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int p = 0;
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &cnt[i]);
			sum[i] = 0;
			for (int j = 1; j <= cnt[i]; j ++) scanf("%d", &b[p+j]), sum[i] += b[p+j];
			p += cnt[i];
			allows[i] = n - (lower_bound(a + 1, a + n + 1, (sum[i] + cnt[i] - 1) / cnt[i]) - a) + 1;
		}
		memset(f, 0, sizeof f);
		for (int i = 1; i <= m; i ++) f[allows[i]] ++;
		for (int i = 1; i <= n; i ++) f[i] = f[i-1] + f[i];
		for (int i = 1; i <= p; i ++) s[i] = '0'; s[p+1] = 0;
		bool invalid = false;
		for (int i = 0; i <= n; i ++) {
			c[i] = f[i] - i;
			if (c[i] > 1) invalid = true;
		}
		if (invalid) {
			puts(s + 1); continue;
		}
		for (int i = 0; i <= n; i ++) mx[i][0] = c[i];
		//for (int i = 0; i <= n; i ++) printf("%d ", c[i]); puts("");
		for (int j = 1; (1 << j) <= n; j ++) {
			for (int i = 0; i + (1 << j) - 1 <= n; i ++) mx[i][j] = max(mx[i][j-1], mx[i+(1<<j-1)][j-1]);
		}
		p = 0;
		//printf("-- %d\n", rmq(0, 1));
		for (int i = 1; i <= m; i ++) {
			for (int j = 1; j <= cnt[i]; j ++) {
				p ++;
				long long tmp = sum[i] - b[p];
				int allow = n - (lower_bound(a + 1, a + n + 1, (tmp + cnt[i] - 1 - 1) / (cnt[i] - 1)) - a) + 1;
			//	printf("%d %d\n", allow, allows[i]);
				if (allow <= 0) continue;
				int mn = min(allow, allows[i]), mx = max(allow, allows[i]);
				if (rmq(0, mn - 1) > 0 || rmq(mx, m) > 0) continue;
			//	puts("ok");
				if (allow > allows[i]) {
					s[p] = '1';
				}
				else if (allow == allows[i]) {
					if (allow > m || c[allow] <= 0) s[p] = '1';
				}
				else {
					if (rmq(allow, allows[i] - 1) <= -1) s[p] = '1';
				}
			}
		}
		puts(s + 1);
	}
	return 0;
}
