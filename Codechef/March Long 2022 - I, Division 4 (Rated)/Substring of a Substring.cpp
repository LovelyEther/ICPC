#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
char s[1001001];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		n = strlen(s);
		ans = -1;
		for (int i = 0, j = n; i < n; i ++) {
			if (s[i] != s[0] && s[i] != s[n-1]) {
				j = min(j, i);
				ans = max(ans, i - j + 1);
			}
			else j = n;
		}
		printf("%d\n", ans);
	}
	return 0;
}
