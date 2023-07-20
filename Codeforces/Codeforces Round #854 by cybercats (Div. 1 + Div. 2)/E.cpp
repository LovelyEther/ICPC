#include <bits/stdc++.h>
using namespace std;

#define N 55

int t, n, m, cnt, mni[N], mxi[N], mnj[N], mxj[N];
char s[N][N];
bool vis[N][N];

void update() {
	while (true) {
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			for (int j1 = 1; j1 <= m; j1 ++) if (s[i][j1] == '#') {
				for (int j2 = j1 + 1; j2 <= m; j2 ++) if (s[i][j2] == '#') {
					for (int j = j1 + 1; j < j2; j ++) if (s[i][j] != '#') {
						s[i][j] = '#', updated = true;
					}
				}
			}
		}
		for (int j = 1; j <= m; j ++) {
			for (int i1 = 1; i1 <= n; i1 ++) if (s[i1][j] == '#') {
				for (int i2 = i1 + 1; i2 <= n; i2 ++) if (s[i2][j] == '#') {
					for (int i = i1 + 1; i < i2; i ++) if (s[i][j] != '#') {
						s[i][j] = '#', updated = true;
					}
				}
			}
		}
		if (!updated) break;
	}
}

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

queue < pair <int, int> > q;

void bfs(int i, int j) {
	mni[cnt] = mnj[cnt] = n + m;
	mxi[cnt] = mxj[cnt] = 0;
	while (!q.empty()) q.pop();
	vis[i][j] = true;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		pair <int, int> p = q.front();
		q.pop();
		i = p.first, j = p.second;
		mni[cnt] = min(mni[cnt], i);
		mxi[cnt] = max(mxi[cnt], i);
		mnj[cnt] = min(mnj[cnt], j);
		mxj[cnt] = max(mxj[cnt], j);
		for (int k = 0; k < 4; k ++) {
			int ii = i + di[k], jj = j + dj[k];
			if (ii < 1 || ii > n || jj < 1 || jj > m) continue;
			if (s[ii][jj] != '#' || vis[ii][jj]) continue;
			vis[ii][jj] = true;
			q.push(make_pair(ii, jj));
		}
	}
}

void print() {
	for (int i = 1; i <= n; i ++) {
		puts(s[i] + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
		update();
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) vis[i][j] = false;
		}
		cnt = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) if (s[i][j] == '#' && !vis[i][j]) cnt ++, bfs(i, j);
		}
		if (cnt == 1) {
			print(); continue;
		}
		if (mxi[1] < mni[2] && mxj[1] < mnj[2]) {
			s[mxi[1]][mxj[1]] = s[mni[2]][mnj[2]] = '#';
			update();
			s[mxi[1]][mnj[2]] = '#';
			update();
		}
		else if (mxi[1] < mni[2] && mnj[1] > mxj[2]) {
			s[mxi[1]][mnj[1]] = s[mni[2]][mxj[2]] = '#';
			update();
			s[mxi[1]][mxj[2]] = '#';
			update();
		}
		else if (mni[1] > mxi[2] && mxj[1] < mnj[2]) {
			s[mni[1]][mxj[1]] = s[mxi[2]][mnj[2]] = '#';
			update();
			s[mni[1]][mnj[2]] = '#';
			update();
		}
		else if (mni[1] > mxi[2] && mnj[1] > mxj[2]) {
			s[mni[1]][mnj[1]] = s[mxi[2]][mxj[2]] = '#';
			update();
			s[mni[1]][mxj[2]] = '#';
			update();
		}
		else assert(0);
		print();
	}
	return 0;
}
