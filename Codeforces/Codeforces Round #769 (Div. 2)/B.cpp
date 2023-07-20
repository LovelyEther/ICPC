#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		m = 31 - __builtin_clz(n - 1);
		for (int i = 1; i < (1 << m); i ++) printf("%d ", i);
		printf("0");
		for (int i = (1 << m); i < n; i ++) printf(" %d", i);
		puts("");
	}
	return 0;
}
