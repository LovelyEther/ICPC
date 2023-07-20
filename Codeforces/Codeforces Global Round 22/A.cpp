#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, type[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &type[i]);
		vector <int> v[2];
		long long sum = 0;
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			sum += x;
			v[type[i]&1].push_back(x);
		}
		for (int i = 0; i < 2; i ++) {
			if (v[i].size() > 0) {
				sort(v[i].begin(), v[i].end());
			}
		}
		if (v[0].size() == v[1].size()) {
			printf("%I64d\n", sum * 2 - min(v[0][0], v[1][0])); continue;
		}
		if (v[0].size() > v[1].size()) swap(v[0], v[1]);
		long long ans = sum * 2;
		for (int i = 0; i < v[1].size() - v[0].size(); i ++) ans -= v[1][i];
		printf("%I64d\n", ans);
	}
	return 0;
}
