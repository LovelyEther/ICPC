#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int t, n, m, vis[N];
char s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i ++) vis[i] = 0;
		for (int i = 0; i < n; i ++) {
			int x;
			scanf("%d", &x);
			x --;
			x = min(x, m - 1 - x);
			vis[x] ++;
		}
		for (int i = 0; i < m; i ++) s[i] = 'B';
		s[m] = 0;
		for (int i = 0; i <= m / 2; i ++) {
			if (vis[i] >= 2) s[i] = s[m-1-i] = 'A';
			else if (vis[i] == 1) s[i] = 'A';
		}
		puts(s);
	}
	return 0;
}
