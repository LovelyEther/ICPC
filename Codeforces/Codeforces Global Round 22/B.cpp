#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, k, s[N], a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = n - k + 1; i <= n; i ++) scanf("%d", &s[i]);
		if (k == 1) {
			puts("YES"); continue;
		}
		bool valid = true;
		for (int i = n - 1; i >= n - k + 1; i --) {
			a[i+1] = s[i+1] - s[i];
			if (i + 1 < n && a[i+1] > a[i+2]) {
				valid = false; break;
			}
		}
		if (!valid) {
			puts("NO"); continue;
		}
		if (1ll * a[n-k+2] * (n - k + 1) >= s[n-k+1]) puts("YES");
		else puts("NO");
	}
	return 0;
}
