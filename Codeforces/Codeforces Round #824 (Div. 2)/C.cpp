#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, prv[N], nxt[N];
char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		memset(prv, -1, sizeof prv);
		memset(nxt, -1, sizeof nxt);
		for (int i = 0; i < n; i ++) {
			int c = s[i] - 'a';
			if (prv[c] != -1) {
				s[i] = prv[c] + 'a'; continue;
			}
			for (int p = 0; p < 26; p ++) if (p != c && nxt[p] == -1) {
				int cnt = 0;
				int x = c;
				while (nxt[x] != -1) x = nxt[x], cnt ++;
				if (x == p && cnt < 25) continue;
				nxt[p] = c, prv[c] = p;
				s[i] = p + 'a';
				break;
			}
		}
		puts(s);
	}
	return 0;
}
