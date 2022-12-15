#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[1001001][11], pr[11], sf[11];
map <string, int> mp;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		mp.clear();
		for (int i = 0; i < n; i ++) scanf("%s", s[i]), mp[s[i]] = 1;
		for (int i = 0; i < n; i ++) {
			int m = strlen(s[i]);
			memset(pr, 0, sizeof pr);
			memset(sf, 0, sizeof sf);
			bool flag = 0;
			for (int j = 0; j < m - 1; j ++) {
				pr[j] = s[i][j];
				strcpy(sf, s[i] + j + 1);
				if (mp.count(pr) && mp.count(sf)) flag = 1;
			}
			if (flag) printf("1");
			else printf("0");
		}
		puts("");
	}
	return 0;
}
