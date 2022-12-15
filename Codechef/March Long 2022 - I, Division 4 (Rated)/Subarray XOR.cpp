#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int mod = 998244353;

int t, n, f[N], ex[N];
char s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	ex[0] = 1;
	for (int i = 1; i < N; i ++) ex[i] = ex[i-1] * 2 % mod;
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s + 1);
		for (int i = 1; i <= n; i ++) {
			f[i] = f[i-1] ^ ((i & 1) && s[i] == '1');
		}
		int ans = 0;
		for (int k = 0; k < n; k ++) {
			if (f[n-k]) ans = (ans + ex[k]) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
