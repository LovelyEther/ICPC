#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, r[N], d[N];
char s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s + 1);
		m = strlen(s + 1);
		r[m+1] = d[m+1] = 0;
		for (int i = m; i >= 1; i --) {
			r[i] = r[i+1];
			d[i] = d[i+1];
			if (s[i] == 'R') r[i] ++;
			else d[i] ++;
		}
		int mr = n - r[1] - 1;
		int md = n - d[1] - 1;
		int row = 1, col = 1;
		bool ar = false, ad = false;
		long long ans = 1;
		for (int i = 1; i <= m; i ++) {
			if (s[i] == 'R') col ++, ar = true;
			else row ++, ad = true;
			ans ++;
			if (ar && s[i+1] != 'R') {
				ans += mr;
			}
			if (ad && s[i+1] != 'D') {
				ans += md;
			}
		}
		if (ar && ad) ans += 1ll * mr * md;
		printf("%I64d\n", ans);
	}
	return 0;
}
