#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &m, &n);
		int ans = 1, prv = 1;
		printf("1");
		for (int i = 2; i <= n; i ++) {
			int r = m % i;
			if (!r) r = i;
			if (r <= prv) ans = prv + 1;
			else ans = prv;
			printf(" %d", ans);
			prv = ans;
		}
		puts("");
	}
	return 0;
}
