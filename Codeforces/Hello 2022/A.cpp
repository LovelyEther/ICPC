#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		if (k > (n + 1) / 2) {
			puts("-1"); continue;
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				printf("%c", i == j && i % 2 == 1 && (i + 1) / 2 <= k ? 'R' : '.');
			}
			puts("");
		}
	}
	return 0;
}
