#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &a, &b);
		int ans = b - a;
		for (int i = 0; i < b - a; i ++) {
			ans = min(ans, i + 1 + (a + i | b) - b);
			for (int j = 0; (1 << j + 1) <= b; j ++) {
				int bb = b >> j << j;
				bb += 1 << j;
				ans = min(ans, i + 1 + (bb - b) + (a + i | bb) - bb);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
