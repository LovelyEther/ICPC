#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[100100];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		if (n & 1) {
			puts("YES"); continue;
		}
		int one = 0;
		for (int i = 0; i < n; i ++) if (s[i] == '1') one ++;
		if (one == n / 2 || one % 2 == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}
