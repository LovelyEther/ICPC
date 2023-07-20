#include <bits/stdc++.h>
using namespace std;

int t;
char s[11];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		for (int i = 0; i < 3; i ++) {
			if ('a' <= s[i] && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
		}
		if (!strcmp(s, "YES")) puts("YES");
		else puts("NO");
	}
	return 0;
}
