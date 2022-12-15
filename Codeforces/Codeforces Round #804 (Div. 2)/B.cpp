#include <bits/stdc++.h>
using namespace std;

#define N 55

int t, n, m, a[N][N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; j += 4) {
			a[0][j] = 1, a[0][j+1] = 0, a[0][j+2] = 0, a[0][j+3] = 1;
		}
		for (int i = 1; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				a[i][j] = a[i-1][j];
				if (i & 1) a[i][j] ^= 1;
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) printf("%d%c", a[i][j], j < m - 1 ? ' ' : '\n');
		}
	}
	return 0;
}
