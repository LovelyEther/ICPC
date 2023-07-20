#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[200200];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		int ans = 0;
		for (int i = 0; i < n; i ++) if (s[i] == '0') {
			if (i + 1 < n && s[i+1] == '0') ans += 2;
			else if (i + 2 < n && s[i+1] == '1' && s[i+2] == '0') ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
