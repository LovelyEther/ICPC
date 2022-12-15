#include <bits/stdc++.h>
using namespace std;

int t;
char s[256], p[256];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s);
		for (int i = 0; i < 6; i ++) p[s[i]] = i;
		if (p['r'] < p['R'] && p['g'] < p['G'] && p['b'] < p['B']) puts("YES");
		else puts("NO");
	}
	return 0;
}
