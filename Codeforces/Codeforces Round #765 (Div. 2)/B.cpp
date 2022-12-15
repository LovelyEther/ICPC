#include <bits/stdc++.h>
using namespace std;

int t, n;
map <int, int> mp;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		mp.clear();
		int ans = -1;
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			if (mp.count(x)) ans = max(ans, n + mp[x] - i);
			mp[x] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
