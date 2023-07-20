#include <bits/stdc++.h>
using namespace std;

#define N 122

const int n = 120;
int t, cx, cy, vis[N][N];
long long m, f[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%I64d %d %d", &m, &cx, &cy);
		if (m < cx + cy) {
			puts("NO"); continue;
		}
		if (!cx && !cy) {
			puts("YES"); continue;
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) f[i][j] = 0, vis[i][j] = 0;
		}
		queue <pair <int, int> > q;
		long long k = m - (cx + cy);
		f[0][0] = k;
		q.push(make_pair(0, 0));
		vis[0][0] = 1;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (y + 1 < n) {
				f[x][y+1] += (f[x][y] + 1) / 2;
				if (!vis[x][y+1]) q.push(make_pair(x, y + 1)), vis[x][y+1] = 1;
			}
			if (x + 1 < n) {
				f[x+1][y] += f[x][y] / 2;
				if (!vis[x+1][y]) q.push(make_pair(x + 1, y)), vis[x+1][y] = 1;
			}
		}
		int x = 0, y = 0, visit = false;
		for (int step = cx + cy; step; step --) {
			if (f[x][y] & 1) x ++;
			else y ++;
			if (x == cx && y == cy) {
				visit = true; break;
			}
			if (x >= n || y >= n) break;
		}
		puts(visit ? "YES" : "NO");
	}
	return 0;
}
