#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		if ((n * k + 1) / 2 % k) {
			puts("NO"); continue;
		}
		vector <int> v;
		for (int i = 1; i <= n * k; i += 2) v.push_back(i);
		for (int i = 2; i <= n * k; i += 2) v.push_back(i);
		int cur = 0;
		puts("YES");
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= k; j ++) printf("%d%c", v[cur++], j < k ? ' ' : '\n');
		}
	}
	return 0;
}
