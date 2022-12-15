#include <bits/stdc++.h>
using namespace std;

int t;
char s[100100], pattern[2];

bool yes() {
	for (int i = 0, len = strlen(s); i < len; i += 2) {
		if (s[i] == pattern[0]) return 1;
	}
	return 0;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s %s", s, pattern);
		if (yes()) puts("YES");
		else puts("NO");
	}
	return 0;
}
