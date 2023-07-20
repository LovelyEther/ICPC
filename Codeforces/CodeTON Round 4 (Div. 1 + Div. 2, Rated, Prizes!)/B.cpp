#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			puts("-1"); continue;
		}
		vector <int> ans;
		while (n > 1) {
			m = n / 2;
			if (m & 1) ans.push_back(2);
			else m ++, ans.push_back(1);
			n = m;
		}
		reverse(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i ++) printf("%d%c", ans[i], i < ans.size() - 1 ? ' ' : '\n');
	}
	return 0;
}
