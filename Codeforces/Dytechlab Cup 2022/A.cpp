#include <bits/stdc++.h>
using namespace std;

#define idx(c) ((c) - 'a')

int t, n, k, cnt[256];
char s[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %s", &n, &k, s);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i ++) cnt[idx(s[i])] ++;
		for (int i = 0; i < k; i ++) {
			int p = -1;
			while (cnt[p+1] && p < 25 && p < n / k - 1) p ++;
			putchar(p + 1 + 'a');
			for (int j = 0; j <= p; j ++) cnt[j] --;
		}
		puts("");
	}
	return 0;
}
