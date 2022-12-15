#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[100100];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		if (n == 1) puts("YES");
		else if (n == 2) {
			if (s[0] == s[1]) puts("NO");
			else puts("YES");
		}
		else puts("NO");
	}
	return 0;
}
