#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t;
char a[N], b[N], s[N];

bool solve(int dp, int la, int ls) {
	if (la <= 0 && !ls) return 1;
	if (!ls) return 0;
	int xa = la > 0 ? a[la-1] - '0' : 0, xs = s[ls-1] - '0';
	if (xa <= xs) {
		b[dp] = '0' + xs - xa; b[dp+1] = 0;
		return solve(dp + 1, la - 1, ls - 1);
	}
	else {
		b[dp] = '0' + xs + 10 - xa; b[dp+1] = 0;
		if (ls == 1 || ls >= 2 && s[ls-2] != '1') return 0;
		return solve(dp + 1, la - 1, ls - 2);
	}
}

int main() {
	//freopen("c.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s %s", a, s);
		if (!solve(0, strlen(a), strlen(s))) puts("-1");
		else {
			strrev(b);
			int p = 0;
			while (b[p] == '0') p ++;
			if (b[p] == 0) p --;
			puts(b + p);
		}
	}
	return 0;
}
