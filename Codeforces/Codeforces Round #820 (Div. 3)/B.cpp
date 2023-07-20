#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		for (int i = 0; i < n; i ++) {
			if (s[i] > '0') {
				if (i + 2 < n && s[i+2] == '0' && (i + 3 >= n || s[i+3] != '0')) {
					int x = (s[i] - '0') * 10 + (s[i+1] - '0');
					putchar('a' + x - 1);
					i += 2;
				}
				else {
					int x = s[i] - '0';
					putchar('a' + x - 1);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
