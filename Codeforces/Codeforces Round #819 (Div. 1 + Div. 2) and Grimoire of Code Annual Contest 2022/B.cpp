#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		if (n > m) {
			puts("No"); continue;
		}
		if (n & 1) {
			puts("Yes");
			for (int i = 1; i < n; i ++) printf("1 ");
			printf("%d\n", m - (n - 1));
		}
		else {
			if (m & 1) puts("No");
			else {
				puts("Yes");
				for (int i = 1; i <= n - 2; i ++) printf("1 ");
				printf("%d %d\n", (m - (n - 2)) / 2, (m - (n - 2)) / 2);
			}
		}
	}
	return 0;
}
