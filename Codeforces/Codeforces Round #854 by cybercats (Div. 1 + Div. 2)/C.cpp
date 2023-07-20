#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, cnt[256];
char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		n = strlen(s);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i ++) cnt[s[i]] ++;
		for (int i = 0, j = n - 1, c = 'a'; c <= 'z'; c ++) {
			while (cnt[c] >= 2) s[i++] = s[j--] = c, cnt[c] -= 2;
			if (cnt[c]) {
				if (i == j) {
					s[i] = c; cnt[c] --; break;
				}
				int d = 0;
				for (int j = c + 1; j <= 'z'; j ++) if (cnt[j]) {
					d = j; break;
				}
				assert(d);
				int e = 0;
				for (int j = d + 1; j <= 'z'; j ++) if (cnt[j]) {
					e = j; break;
				}
				if (!e) {
					while (cnt[d] >= 2) s[i++] = s[j--] = d, cnt[d] -= 2;
					if (cnt[d]) s[i++] = d, cnt[d] --;
					s[j--] = c;
				}
				else {
					s[j--] = c, cnt[c] --;
					for (int j = c + 1; j <= 'z'; j ++) {
						while (cnt[j]) s[i++] = j, cnt[j] --;
					}
				}
				break;
			}
		}
		puts(s);
	}
	return 0;
}
