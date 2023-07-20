#include <bits/stdc++.h>
using namespace std;

int t, n, a[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		vector <int> v, w;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if (a[i] & 1) v.push_back(i);
			else w.push_back(i);
		}
		vector < pair <int, int> > ans;
		if (a[1] % 2) {
			if (v.size() >= 2) {
				for (int i = v.size() - 2; i >= 0; i --) {
					ans.push_back(make_pair(v[i], v[i+1]));
				}
			}
			for (int i = 0; i < w.size(); i ++) {
				ans.push_back(make_pair(1, w[i]));
			}
		}
		else {
			if (w.size() >= 2) {
				for (int i = w.size() - 2; i >= 0; i --) {
					ans.push_back(make_pair(w[i], w[i+1]));
				}
			}
			for (int i = 0; i < v.size(); i ++) {
				ans.push_back(make_pair(1, v[i]));
			}
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i ++) printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
