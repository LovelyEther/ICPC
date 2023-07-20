#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m;
vector <int> v[N], s[N], t[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int x;
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			s[v[i][j]].push_back(i);
			t[v[i][j]].push_back(j);
		}
	}
	long long ans = 0;
	for (int x = 1; x < N; x ++) {
		sort(s[x].begin(), s[x].end());
		int sz = s[x].size();
		for (int i = 0; i + 1 < sz; i ++) ans += 1ll * (i + 1) * (sz - i - 1) * (s[x][i+1] - s[x][i]);
		sort(t[x].begin(), t[x].end());
		sz = t[x].size();
		for (int i = 0; i + 1 < sz; i ++) ans += 1ll * (i + 1) * (sz - i - 1) * (t[x][i+1] - t[x][i]);
	}
	printf("%I64d\n", ans);
	return 0;
}
