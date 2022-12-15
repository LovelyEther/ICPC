#include <bits/stdc++.h>
using namespace std;

#define N 111

int t, n, l, a[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
		int ans = 0;
		for (int j = 0; j < l; j ++) {
			int cnt = 0;
			for (int i = 0; i < n; i ++) if (a[i] & (1 << j)) cnt ++;
			if (cnt > n - cnt) ans ^= 1 << j;
		}
		printf("%d\n", ans);
	}
	return 0;
}
