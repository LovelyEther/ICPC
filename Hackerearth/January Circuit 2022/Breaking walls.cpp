#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, C, col[N][N], score[N*N];
char s[N][N];

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

bool valid(int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}

void dfs(int i, int j) {
	if (s[i][j] == '#') return;
	col[i][j] = C;
	for (int k = 0; k < 4; k ++) {
		int ii = i + di[k], jj = j + dj[k];
		if (!valid(ii, jj)) continue;
		if (!col[ii][jj]) dfs(ii, jj);
	}
	if (s[i][j] == '*') score[C] ++;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) if (!col[i][j]) C ++, dfs(i, j);
	}
	int ans = 0;
	for (int i = 1; i <= C; i ++) ans = max(ans, score[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			for (int k = 0; k < 4; k ++) {
				int i1 = i + di[k], j1 = j + dj[k];
				if (!valid(i1, j1)) continue;
				for (int l = 0; l < 4; l ++) {
					int i2 = i + di[l], j2 = j + dj[l];
					if (!valid(i2, j2)) continue;
					if (col[i1][j1] != col[i2][j2]) ans = max(ans, score[col[i1][j1]] + score[col[i2][j2]]);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
