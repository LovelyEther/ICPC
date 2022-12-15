#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n == 2) puts("NO");
		else if (n & 1) {
			puts("YES");
			for (int i = 1; i <= n / 2; i ++) printf("%d ", i);
			for (int i = n; i > n / 2; i --) printf("%d%c", i, i > n / 2 + 1 ? ' ' : '\n');
		}
		else {
			puts("YES");
			printf("2 1");
			for (int i = 3; i <= n / 2; i ++) printf(" %d", i);
			for (int i = n; i > n / 2; i --) printf(" %d", i);
			puts("");
		}
	}
	return 0;
}
