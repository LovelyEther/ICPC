#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[300300];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		scanf("%s", s);
		if (s[0] == '1' && s[1] == '1' && s[n] == '1') {
			puts("Yes");
			printf("0");
			for (int i = 2, last = 0; i <= n; i ++) if (s[i] == '1') {
				printf(" %d", i - 1);
				for (int j = i - 2; j > last; j --) printf(" %d", j);
				last = i - 1;
			}
			puts("");
		}
		else {
			puts("No");
		}
	}
	return 0;
}
