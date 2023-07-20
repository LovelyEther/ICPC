#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int t, n, x;
multiset <pii> s;
multiset <pii> :: iterator it;
vector <pii> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		s.clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			s.insert(make_pair(x, i));
		}
		if ((*s.begin()).first == 1 && (*s.rbegin()).first > 1) {
			puts("-1"); continue;
		}
		ans.clear();
		while ((*s.begin()).first < (*s.rbegin()).first) {
			auto x = *s.rbegin();
			auto y = *s.begin();
			ans.push_back(make_pair(x.second, y.second));
			it = s.find(x);
			s.erase(it);
			s.insert(make_pair((x.first + y.first - 1) / y.first, x.second));
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i ++) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}
