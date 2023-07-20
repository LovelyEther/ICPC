#include <bits/stdc++.h>
using namespace std;

int t, l, r, k;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &l, &r, &k);
		if (l == r) {
			puts(l > 1 ? "YES" : "NO"); continue;
		}
		puts((r + 1) / 2 - l / 2 <= k ? "YES" : "NO");
	}
	return 0;
}
