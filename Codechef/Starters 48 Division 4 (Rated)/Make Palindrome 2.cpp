#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[200200];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		int zero = 0, one = 0;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '0') zero ++;
			else one ++;
		}
		if (zero > one) {
			for (int i = 0; i < zero; i ++) printf("0");
		}
		else {
			for (int i = 0; i < one; i ++) printf("1");
		}
		puts("");
	}
	return 0;
}
