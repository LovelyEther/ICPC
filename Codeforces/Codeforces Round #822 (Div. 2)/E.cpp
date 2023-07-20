#include <bits/stdc++.h>
using namespace std;

#define N 404

int t, n, b[N], a[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < n; j ++) {
			a[i][(i+j-1)%n+1] = (b[i] + i * j) % n;
		}
		for (int j = 1; j <= n; j ++) printf("%d ", a[i][j]); puts("");
	}
	return 0;
}
