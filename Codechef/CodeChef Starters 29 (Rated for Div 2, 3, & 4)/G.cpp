#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, q, l, r, c[N], f[N];
char A[N], B[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &q);
		scanf("%s %s", A + 1, B + 1);
		for (int i = 1; i <= n; i ++) c[i] = B[i] - A[i];
		for (int i = 1; i <= n; i ++) {
			if (i & 1) f[i] = f[i-1] + c[i];
			else f[i] = f[i-1] - c[i];
		}
		while (q --) {
			scanf("%d %d", &l, &r);
			if ((f[r] - f[l-1]) % 26 == 0) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
