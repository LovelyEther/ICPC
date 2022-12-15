#include <bits/stdc++.h>
using namespace std;

#define N 300300

int t, n, m, a[N], occur[N], val[N];
vector <int> v[N];
map <int, int> mp;
set <int> ids[N], occurs;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		mp.clear();
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (!mp[a[i]]) {
				mp[a[i]] = ++ cnt;
				val[cnt] = a[i];
				occur[cnt] = 0;
			}
			occur[mp[a[i]]] ++;
		}
		for (int i = 1; i <= n; i ++) ids[i].clear();

		occurs.clear();
		for (int i = 1; i <= cnt; i ++) {
			ids[occur[i]].insert(val[i]);
			occurs.insert(occur[i]);
		}

		for (int i = 1; i <= cnt; i ++) v[i].clear();
		for (int i = 1; i <= m; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			x = mp[x], y = mp[y];
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= cnt; i ++) {
			v[i].push_back(i);
			sort(v[i].begin(), v[i].end());
		}
		long long ans = 0;
		for (int i = 1; i <= cnt; i ++) {
			for (int j = 0; j < v[i].size(); j ++) {
				int rest = v[i][j];
				ids[occur[rest]].erase(val[rest]);
			}

			for (set <int> :: iterator it = occurs.begin(); it != occurs.end(); it ++) {
				int x = *it;
				if (ids[x].empty()) continue;
				set <int> :: iterator jt = ids[x].end();
				jt --;
				int y = *jt;
				ans = max(ans, 1ll * (occur[i] + occur[mp[y]]) * (val[i] + y));
			}

			for (int j = 0; j < v[i].size(); j ++) {
				int rest = v[i][j];
				ids[occur[rest]].insert(val[rest]);
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
