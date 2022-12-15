#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m;
set <int> s[N], rem;
set <int> :: iterator it;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		rem.clear();
		for (int i = 1; i <= n; i ++) s[i].clear(), rem.insert(i);
		for (int i = 1; i <= m; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			s[y].insert(x);
			rem.erase(x);
		}
		for (it = rem.begin(); it != rem.end(); it ++) s[n].insert(*it);
		bool valid = true;
		int last = n;
		vector <int> v;
		for (int i = n; i >= 1; i --) {
			if (s[last].size() < 1) {
				valid = false; break;
			}
			int x = *s[last].rbegin();
			s[last].erase(x);
			v.push_back(x);
			if (s[i-1].size() > s[last].size()) {
				for (it = s[last].begin(); it != s[last].end(); it ++) s[i-1].insert(*it);
				last = i - 1;
			}
			else {
				for (it = s[i-1].begin(); it != s[i-1].end(); it ++) s[last].insert(*it);
			}
		}
		if (!valid) {
			puts("-1");
		}
		else {
			for (int i = v.size() - 1; i >= 0; i --) printf("%d%c", v[i], i > 0 ? ' ' : '\n');
		}
	}
	return 0;
}
