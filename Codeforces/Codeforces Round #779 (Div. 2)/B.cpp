#include <bits/stdc++.h>
using namespace std;

#define N 1010

const int mod = 998244353;

int t, n, fact[N];

int main() {
//	freopen("in.txt", "r", stdin);
	fact[0] = 1;
	for (int i = 1; i < N; i ++) fact[i] = 1ll * fact[i-1] * i % mod;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int ans = 0;
		if (n % 2 == 0) ans = 1ll * fact[n/2] * fact[n/2] % mod;
		printf("%d\n", ans);
	}
	return 0;
}
