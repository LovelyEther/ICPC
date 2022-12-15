#include <bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, a, b, na, nb, m, r, cnt[2];
char s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < n; i ++) cnt[s[i]-'0'] ++;
		if (cnt[0] <= cnt[1]) {
			a = '0', b = '1';
			na = cnt[0], nb = cnt[1];
		}
		else {
			a = '1', b = '0';
			na = cnt[1], nb = cnt[0];
		}
		m = nb / (na + 1), r = nb % (na + 1);
		for (int i = 0; i <= na; i ++) {
			for (int j = 0; j < m + (i < r); j ++) putchar(b);
			putchar(i < na ? a : '\n');
		}
		for (int i = 0; i < na; i ++) putchar(a);
		for (int i = 0; i < nb; i ++) putchar(b);
		putchar('\n');
	}
	return 0;
}
