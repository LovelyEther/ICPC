#include <bits/stdc++.h>
using namespace std;

int t, n, m, p[22];
vector <long long> v;

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %lld", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
		v.clear();
		v.push_back(1);
		for (int i = 1; i <= n; i ++) {
			int sz = v.size();
			long long x = p[i];
			while (x <= m) {
				for (int j = 0; j < sz; j ++) {
					if (v[j] <= m / x) v.push_back(v[j] * x);
				}
				x *= p[i];
			}
		}
		printf("%d\n", v.size());
	}
	return 0;
}
