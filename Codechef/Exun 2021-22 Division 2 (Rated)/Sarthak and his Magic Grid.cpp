#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) printf("%d%c", 1, j < n ? ' ' : '\n');
		}
	}
	return 0;
}
