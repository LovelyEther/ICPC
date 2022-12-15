#include <bits/stdc++.h>
using namespace std;

#define N 2020

int t, n, a[N], b[N], f[N][N];
char A[N], B[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s %s", &n, A + 1, B + 1);
		for (int i = 1; i <= n; i ++) {
			a[i] = a[i-1] + (A[i] == '1');
			b[i] = b[i-1] + (B[i] == '1');
		}
		for (int i = 0; i <= n; i ++) {
			for (int j = 0; j <= n; j ++) {
				if (i || j) f[i][j] = 1e9;
				if (i) {
					if (A[i] == '1') f[i][j] = min(f[i][j], f[i-1][j]);
					else f[i][j] = min(f[i][j], f[i-1][j] + a[i-1] + b[j]);
				}
				if (j) {
					if (B[j] == '1') f[i][j] = min(f[i][j], f[i][j-1]);
					else f[i][j] = min(f[i][j], f[i][j-1] + a[i] + b[j-1]);
				}
			}
		}
		printf("%d\n", f[n][n]);
	}
	return 0;
}
