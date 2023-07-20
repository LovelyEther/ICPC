#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, a[N], st[N], en[N], f[N], mx[N];

void add(int x, int val) {
	while (x <= n) mx[x] = max(mx[x], val), x += x & -x;
}

int calc(int x) {
	int rlt = 0;
	while (x) rlt = max(rlt, mx[x]), x -= x & -x;
	return rlt;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) if (!st[a[i]]) st[a[i]] = i;
	for (int i = n; i >= 1; i --) if (!en[a[i]]) en[a[i]] = i;
	for (int i = 1; i <= n; i ++) if (st[i] != en[i]) f[st[i]] = en[i];
	for (int i = 1; i <= n; i ++) add(i, f[i]);

	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (f[i]) {
			ans += f[i] - i - 1;
			int j = f[i];
			while (j <= n) {
				int k = calc(j);
				if (k <= j) break;
				ans += k - j - 1;
				j = k;
			}
			i = j;
		}
	}
	printf("%d\n", ans);
	return 0;
}
