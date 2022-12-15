#include <bits/stdc++.h>
using namespace std;

int t, n, flag[256];
char s[1001001];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		memset(flag, 0, sizeof flag);
		for (int i = 0; i < n; i ++) flag[s[i]-'A'] = 1;
		int ans = n;
		for (int i = 0; i < 26; i ++) ans += flag[i];
		printf("%d\n", ans);
	}
	return 0;
}
