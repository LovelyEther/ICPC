#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int ans = 0;
		set <int> s;
		int cap = 0;
		for (int i = 1; i <= n; i ++) {
			if (s.find(cap) != s.end() || a[i] == 0) {
				s.clear();
				cap = 0;
				continue;
			}
			s.insert(a[i] ^ cap);
			ans ++;
			cap ^= a[i+1];
		}
		printf("%d\n", ans);
	}
	return 0;
}
