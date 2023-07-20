#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, a[200200];
priority_queue < pair <int, int> > pq;

int main() {
	//freopen("f.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &m, &k);
		while (!pq.empty()) pq.pop();
		for (int i = 1; i <= n; i ++) a[i] = 0;
		for (int i = 1; i <= n; i ++) pq.push(make_pair(a[i], i));
		int p = n / m, r = n % m;
		for (int i = 1; i <= k; i ++) {
			vector <int> ans;
			for (int j = 0; j < m; j ++) {
				int cnt = p + (j < r);
				ans.clear();
				while (cnt --) {
					pair <int, int> x = pq.top(); pq.pop();
					ans.push_back(x.second);
					if (j < r) a[x.second] --;
				}
				printf("%d", p + (j < r));
				for (int _ = 0; _ < ans.size(); _ ++) printf(" %d", ans[_]); puts("");
			}
			assert(pq.empty());
			for (int j = 1; j <= n; j ++) pq.push(make_pair(a[j], j));
		}
		puts("");
	}
	return 0;
}
