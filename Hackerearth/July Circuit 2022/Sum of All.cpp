#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return rlt;
}

int t;
char s[100100];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			ans = (ans + 1ll * (s[i] - '0') * (1ll * expmod(2, i - 1) * expmod(11, n - i) - expmod(10, n - i))) % mod;
		}
		printf("%d\n", (ans + mod) % mod);
	}
	return 0;
}
