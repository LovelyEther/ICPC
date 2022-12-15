#include <bits/stdc++.h>
using namespace std;

#define N 2020

int t, n, f[N][N];
char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		n = strlen(s + 1) / 2;
		for (int i = 1; i <= 2 * n; i ++) {
			for (int j = 1;j <= 2 * n; j ++) f[i][j] = 0;
		}
		for (int d = 2; d <= 2 * n; d += 2) {
			for (int i = 1; i + d - 1 <= 2 * n; i ++) {
				int j = i + d - 1;
				if (d == 2) {
					if (s[i] != s[j]) f[i][j] = 2;
					else f[i][j] = 1;
					continue;
				}
				if ((f[i+1][j-1] == 2 || s[i] < s[j] && f[i+1][j-1] == 1) && (f[i+2][j] == 2 || s[i] < s[i+1] && f[i+2][j] == 1)) f[i][j] = 2;
				else if ((f[i][j-2] == 2 || s[j] < s[j-1] && f[i][j-2] == 1) && (f[i+1][j-1] == 2 || s[j] < s[i] && f[i+1][j-1] == 1)) f[i][j] = 2;
				else if ((f[i+1][j-1] == 0 || s[i] > s[j] && f[i+1][j-1] == 1 || f[i+2][j] == 0 || s[i] > s[i+1] && f[i+2][j] == 1) &&
							(f[i][j-2] == 0 || s[j] > s[j-1] && f[i][j-2] == 1 || f[i+1][j-1] == 0 || s[j] > s[i] && f[i+1][j-1] == 1)) f[i][j] = 0;
				else f[i][j] = 1;
			}
		}
		if (f[1][2*n] == 2) puts("Alice");
		else if (f[1][2*n] == 1) puts("Draw");
		else puts("Bob");
	}
	return 0;
}
