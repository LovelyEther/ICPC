#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		vector <int> ans;
		int x = 1;
		for (int i = 1; i <= n; i ++) {
			ans.push_back(x);
			if (3ll * x <= 1e9) x *= 3;
			else break;
		}
		if (ans.size() == n) {
			puts("YES");
			for (int i = 0; i < n; i ++) printf("%d%c", ans[i], i < ans.size() - 1 ? ' ' : '\n');
		}
		else {
			puts("NO");
		}
	}
	return 0;
}
