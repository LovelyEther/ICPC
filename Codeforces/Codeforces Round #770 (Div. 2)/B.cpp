#include <bits/stdc++.h>
using namespace std;

int t, n, x, z;
long long y;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %I64d", &n, &x, &y);
		for (int i = 0; i < n; i ++) {
			scanf("%d", &z);
			x = (x + z) % 2;
		}
		if (x % 2 == y % 2) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
