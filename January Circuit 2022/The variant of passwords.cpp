#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;
char s[200200];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &a, &b);
		scanf("%s", s);
		int zero = 0, one = 0;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '0') zero ++;
			else if (s[i] == '1') one ++;
		}
		int ans = 0, zero2one = 0;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '1' && zero < a && one > b) s[i] = '0', zero ++, one --, ans ++;
		}
		for (int i = n - 1; i >= 0; i --) {
			if (s[i] == '0' && zero > a && one < b) zero2one ++, zero --, one ++, ans ++;
		}
		if (zero >= a && one >= b) {
			for (int i = n - 1; i >= 0; i --) {
				if (s[i] == '0' && zero > a) s[i] = '2', zero --, ans ++;
				else if (s[i] == '0' && zero2one) s[i] = '1', zero2one --;
				else if (s[i] == '1' && one > b) s[i] = '2', one --, ans ++;
			}
		}
		else {
			for (int i = n - 1; i >= 0; i --) if (s[i] == '0' && zero2one) s[i] = '1', zero2one --;
			for (int i = 0; i < n; i ++) if (s[i] == '2') {
				if (zero < a) s[i] = '0', zero ++, ans ++;
				else if (one < b) s[i] = '1', one ++, ans ++;
			}
		}
		printf("%d\n%s\n", ans, s);
	}
	return 0;
}
