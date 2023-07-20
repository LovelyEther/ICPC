#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n & 1) {
			printf("1 ");
			for (int i = 2; i <= n; i += 2) printf("%d %d ", i + 1, i);
		}
		else {
			for (int i = 1; i <= n; i += 2) printf("%d %d ", i + 1, i);
		}
		puts("");
	}
	return 0;
}
