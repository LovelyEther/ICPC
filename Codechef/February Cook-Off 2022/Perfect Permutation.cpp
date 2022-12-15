#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		if (k == n) {
			for (int i = 1; i <= n; i ++) printf("%d%c", i, i < n ? ' ' : '\n');
		}
		else {
			printf("%d", k + 1);
			for (int i = 2; i <= k; i ++) printf(" %d", i);
			for (int i = k + 2; i <= n; i ++) printf(" %d", i);
			printf(" %d\n", 1);
		}
	}
	return 0;
}
