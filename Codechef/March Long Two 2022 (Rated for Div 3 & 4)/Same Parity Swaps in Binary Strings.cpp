#include <bits/stdc++.h>
using namespace std;

int t, n, cnt[2][2], ans;
char s[100100];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i ++) cnt[i&1][s[i]-'0'] ++;
		ans = min(cnt[0][0], cnt[1][1]) + min(cnt[0][1], cnt[1][0]);
		if (cnt[0][0] == cnt[1][1] && cnt[0][1] && cnt[0][1] == cnt[1][0]) ans --;
		printf("%d\n", ans);
	}
	return 0;
}
