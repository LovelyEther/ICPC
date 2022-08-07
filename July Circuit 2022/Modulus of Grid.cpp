#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, q, phi[N];
vector <int> fac[N];

int main() {
	for (int i = 1; i < N; i ++) phi[i] = i;
	for (int i = 1; i < N; i ++) {
		for (int j = i; j < N; j += i) fac[j].push_back(i);
		if (phi[i] == i && i > 1) {
			for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
		}
	}
	scanf("%d %d %d", &n, &m, &q);
	while (q --) {
		int x, y, xx, yy, a = 0, b = 0;
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		x = (xx - x + n) % n;
		y = (yy - y + m) % m;
		if (!x) a = n - 1;
		else {
			int d = __gcd(x, n);
			for (int i = 0; i < fac[d].size(); i ++) a += phi[n/fac[d][i]];
		}
		if (!y) b = m - 1;
		else {
			int d = __gcd(y, m);
			for (int i = 0; i < fac[d].size(); i ++) b += phi[m/fac[d][i]];
		}
		printf("%lld\n", 1ll * a * b);
	}
	return 0;
}
