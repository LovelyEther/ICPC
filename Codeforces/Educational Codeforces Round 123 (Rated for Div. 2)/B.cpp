#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n == 3) {
			puts("3 2 1");
			puts("1 3 2");
			puts("3 1 2");
			continue;
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i + n; j > i; j --) printf("%d ", (j - 1) % n + 1); puts("");
		}
	}
	return 0;
}
