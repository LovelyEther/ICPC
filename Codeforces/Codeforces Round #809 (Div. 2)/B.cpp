#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, f[N];
vector <int> v[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for (int i = 1; i <= n; i ++) {
			if (v[i].size() == 0) {
				printf("0 "); continue;
			}
			int m = v[i].size();
			for (int j = 0; j < m; j ++) f[j] = 1;
			int odd = -1, even = -1;
			for (int j = 0; j < m; j ++) {
				if (v[i][j] % 2 == 1) {
					if (even != -1) f[j] = f[even] + 1;
				}
				else {
					if (odd != -1) f[j] = f[odd] + 1;
				}
				if (v[i][j] % 2 == 0) even = j;
				else odd = j;
			}
			int ans = 0;
			for (int j = 0; j < m; j ++) ans = max(ans, f[j]);
			printf("%d ", ans);
		}
		puts("");
	}
	return 0;
}
