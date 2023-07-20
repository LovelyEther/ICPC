#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], b[N];
long long s[N], c[N], r[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i ++) {
			s[i] = s[i-1] + b[i];
			c[i] = r[i] = 0;
		}
		for (int i = 1; i <= n; i ++) {
			if (a[i] <= b[i]) {
				r[i] += a[i]; continue;
			}
			int st = i, en = n + 1;
			while (en - st > 1) {
				int md = st + en >> 1;
				if (s[md] - s[i-1] <= a[i]) st = md;
				else en = md;
			}
			c[i] ++;
			c[st+1] --;
			r[st+1] += a[i] - (s[st] - s[i-1]);
		}
		for (int i = 1; i <= n; i ++) {
			c[i] += c[i-1];
			printf("%I64d%c", c[i] * b[i] + r[i], i < n ? ' ' : '\n');
		}
	}
	return 0;
}
