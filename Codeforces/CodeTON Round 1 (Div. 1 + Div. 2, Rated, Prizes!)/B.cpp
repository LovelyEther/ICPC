#include <bits/stdc++.h>
using namespace std;

int t, n, k, x;
map <int, int> mp;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		mp.clear();
		bool ans = false;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			if (mp.count(x + k) || mp.count(x - k)) ans = true;
			mp[x] = 1;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
