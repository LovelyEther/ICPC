#include <bits/stdc++.h>
using namespace std;

int t, q, type, a, b, n;
long long h_min, h_max;

long long calc(int a, int b, long long h) {
	if (h <= a) return 1;
	return (h - b - 1) / (a - b) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &q);
		h_min = 0, h_max = 1ll << 60;
		while (q --) {
			scanf("%d", &type);
			if (type == 1) {
				scanf("%d %d %d", &a, &b, &n);
				long long mn = a + 1ll * (n - 2) * (a - b) + 1;
				long long mx = a + 1ll * (n - 1) * (a - b);
				if (n == 1) mn = 0;
				if (h_min > mx || h_max < mn) printf("0 ");
				else {
					printf("1 ");
					h_min = max(h_min, mn);
					h_max = min(h_max, mx);
				}
			}
			else {
				scanf("%d %d", &a, &b);
				long long n1 = calc(a, b, h_min);
				long long n2 = calc(a, b, h_max);
				if (n1 == n2) printf("%I64d ", n1);
				else printf("-1 ");
			}
		}
		puts("");
	}
	return 0;
}
