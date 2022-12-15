#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[100100];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		n = strlen(s);
		if (n & 1) {
			puts("NO"); continue;
		}
		n /= 2;
		bool yes = true;
		for (int i = 0; i < n; i ++) if (s[i] != s[n+i]) yes = false;
		puts(yes ? "YES" : "NO");
	}
	return 0;
}
