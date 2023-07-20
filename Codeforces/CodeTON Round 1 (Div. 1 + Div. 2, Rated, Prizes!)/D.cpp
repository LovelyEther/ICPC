#include <bits/stdc++.h>
using namespace std;

int t;
long long n, m;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%I64d", &n);
		m = n;
		while (m % 2 == 0) m /= 2;
		if (m == 1) {
			puts("-1"); continue;
		}
		if (m == n) {
			puts("2"); continue;
		}
		if (m <= n / m * 2 - 1) printf("%I64d\n", m);
		else printf("%I64d\n", n / m * 2);
	}
	return 0;
}
