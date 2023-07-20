#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], p[N], id[N], f[N];

bool cmp(int i, int j) {
	return p[i] < p[j];
}

void add(int x) {
	while (x <= n) f[x] ++, x += x & -x;
}

int calc(int x) {
	int rlt = 0;
	while (x) rlt += f[x], x -= x & -x;
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), p[i] = max(1, i - a[i] + 1), id[i] = i, f[i] = 0;
		sort(id + 1, id + n + 1, cmp);
		long long ans = 0;
		int last = 0;
		for (int i = 1; i <= n; i ++) {
			while (last < n && p[id[last+1]] == i) {
				last ++;
				add(id[last]);
			}
			int st = i, en = n + 1;
			while (en - st > 1) {
				int md = st + en >> 1;
				if (calc(md) == md) st = md;
				else en = md;
			}
			ans += st - i + 1;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
