#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, f[N], x[N];
vector <int> v[N];

void add(int x) {
	while (x <= n) f[x] ++, x += x & -x;
}

int calc(int x) {
	int rlt = 0;
	while (x) rlt += f[x], x -= x & -x;
	return rlt;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i ++) f[i] = 0, v[i].clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x[i]);
			if (x[i] < i && x[i]) v[x[i]].push_back(x[i]);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < v[i].size(); j ++) {
				ans += calc(v[i][j] - 1);
			}
			if (x[i] < i) add(max(x[i], 1));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
