#include <bits/stdc++.h>
using namespace std;

int t, n, m;
char s[100100];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		scanf("%s", s);
		bool palindrome = true;
		for (int i = 0; i < n; i ++) if (s[i] != s[n-1-i]) palindrome = false;
		if (!m || palindrome) puts("1");
		else puts("2");
	}
	return 0;
}
