#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, l, a[N], f[N], g[N];

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), f[i] = g[i] = a[i];
		for (int i = 2; i <= n; i ++) f[i] = max(f[i-1], f[i]);
		for (int i = n - 1; i >= 1; i --) g[i] = min(g[i], g[i+1]);
		bool ans = true;
		for (int i = 1; i < n; i ++) {
			if (f[i] > g[i+1]) ans = false;
		}
		puts(!ans ? "YES" : "NO");
	}
	return 0;
}
