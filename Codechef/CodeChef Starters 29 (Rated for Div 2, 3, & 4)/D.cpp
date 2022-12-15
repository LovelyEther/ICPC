#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
char s[100100];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		ans = 0;
		for (int i = 0; i < n; i ++) {
			ans ++;
			if (i + 1 < n && s[i+1] == s[i]) i ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
