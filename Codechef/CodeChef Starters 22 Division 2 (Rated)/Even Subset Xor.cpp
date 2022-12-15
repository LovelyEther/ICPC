#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			int k = 0;
			for (int j = 0; j < 10; j ++) if (i & (1 << j)) k ^= (1 << 2 * j) ^ (1 << 2 * j + 1);
			printf("%d%c", k, i < n - 1 ? ' ' : '\n');
		}
	}
	return 0;
}
