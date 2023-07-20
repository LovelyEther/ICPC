#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001001], m;
char s[1001001];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) {
			scanf("%d %s", &m, s);
			for (int j = 0; j < m; j ++) {
				if (s[j] == 'U') a[i] --;
				else a[i] ++;
			}
			a[i] = (a[i] % 10 + 10) % 10;
		}
		for (int i = 1; i <= n; i ++) printf("%d%c", a[i], i < n ? ' ' : '\n');
	}
	return 0;
}
