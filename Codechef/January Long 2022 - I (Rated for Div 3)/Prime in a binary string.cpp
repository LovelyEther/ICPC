#include <bits/stdc++.h>
using namespace std;

int t;
char s[100100];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		int n = strlen(s);
		bool yes = false;
		for (int i = 0; i < n; i ++) if (s[i] == '1' && i < n - 1) yes = true;
		puts(yes ? "Yes" : "No");
	}
	return 0;
}
