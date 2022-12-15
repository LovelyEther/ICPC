#include <bits/stdc++.h>
using namespace std;

int t, n, x, a, b, c;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		a = (n + x) / 4;
		c = n + x - 4 * a;
		b = n - a - c;
		if (b < 0) puts("NO");
		else {
			puts("YES");
			printf("%d %d %d\n", a, b, c);
		}
	}
	return 0;
}
