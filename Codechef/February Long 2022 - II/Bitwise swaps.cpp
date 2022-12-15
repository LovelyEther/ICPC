#include <bits/stdc++.h>
using namespace std;

#define N 300300

int t, n, a[N], T, vis[N], head, tail, q[N];
vector <int> v[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int j = 0; j < 31; j ++) {
			vector <int> ids;
			for (int i = 1; i <= n; i ++) if (a[i] & (1 << j)) ids.push_back(i);
			for (int i = 1; i < ids.size(); i ++) {
				int a = ids[i-1], b = ids[i];
				v[a].push_back(b);
				v[b].push_back(a);
			}
		}
		T ++;
		for (int i = 1; i <= n; i ++) if (vis[i] != T) {
			head = tail = 0;
			vis[i] = T;
			q[tail++] = i;
			while (head < tail) {
				int x = q[head++];
				for (int j = 0; j < v[x].size(); j ++) {
					int y = v[x][j];
					if (vis[y] == T) continue;
					vis[y] = T;
					q[tail++] = y;
				}
			}
			vector <int> w;
			for (int j = 0; j < tail; j ++) w.push_back(a[q[j]]);
			sort(w.begin(), w.end());
			sort(q, q + tail);
			for (int j = 0; j < tail; j ++) a[q[j]] = w[j];
		}
		bool sorted = true;
		for (int i = 1; i < n; i ++) if (a[i] > a[i+1]) sorted = false;
		puts(sorted ? "Yes" : "No");
	}
	return 0;
}
