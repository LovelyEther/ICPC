#include <bits/stdc++.h>
using namespace std;

#define N 100100

const long long inf = 1ll << 60;

int t, n, m, k, id[N], x[N], a[N], b[N], c[N], d[N], h[N];
long long f[N];
vector <long long> v[N], w[N];
vector <int> pos[N];

bool cmp(int i, int j) {
	return c[i] != c[j] ? c[i] < c[j] : d[i] < d[j];
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
		for (int i = 1; i <= k; i ++) scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &h[i]), id[i] = i, f[i] = inf;
		sort(id + 1, id + k + 1, cmp);
		for (int i = 1; i <= n; i ++) v[i].clear(), w[i].clear(), pos[i].clear();
		v[1].push_back((m - 1) * x[1]);
		w[1].push_back(0);
		pos[1].push_back(1);
		for (int i = 1; i <= k; i ++) {
			int r = id[i];
			f[r] = inf;
			int flr = a[r];
			if (pos[flr].size() > 0) {
				if (pos[flr][0] <= b[r]) {
					int st = 0, en = pos[flr].size();
					while (en - st > 1) {
						int mid = st + en >> 1;
						if (pos[flr][mid] <= b[r]) st = mid;
						else en = mid;
					}
					f[r] = min(f[r], v[flr][st] - 1ll * (m - b[r]) * x[flr] - h[r]);
				}
				if (pos[flr][pos[flr].size()-1] > b[r]) {
					int st = -1, en = pos[flr].size() - 1;
					while (en - st > 1) {
						int mid = (st + en) / 2;
						if (pos[flr][mid] > b[r]) en = mid;
						else st = mid;
					}
					f[r] = min(f[r], w[flr][en] - 1ll * (b[r] - 1) * x[flr] - h[r]);
				}
			}
			if (i == k || i < k && c[id[i+1]] > c[id[i]]) {
				int top = c[r];
				int sti = i;
				while (sti > 1 && c[id[sti-1]] == top) sti --;
				for (int j = sti; j <= i; j ++) if (f[id[j]] < inf) {
					pos[top].push_back(d[id[j]]);
					v[top].push_back(f[id[j]] + 1ll * (m - d[id[j]]) * x[top]);
					w[top].push_back(f[id[j]] + 1ll * (d[id[j]] - 1) * x[top]);
				}
				for (int j = 1; j < v[top].size(); j ++) v[top][j] = min(v[top][j], v[top][j-1]);
				for (int j = w[top].size() - 2; j >= 0; j --) w[top][j] = min(w[top][j], w[top][j+1]);
			}
		}
		if (v[n].size() == 0) puts("NO ESCAPE");
		else printf("%I64d\n", v[n][v[n].size()-1]);
	}
	return 0;
}
