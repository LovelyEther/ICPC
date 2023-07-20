#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b) {
	if (a > 0 && b > 0) return min(a, b);
	if (a < 0 && b < 0) return abs(max(a, b));
	return 0;
}

int t, x[3], y[3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		for (int i = 0; i < 3; i ++) {
			scanf("%d %d", &x[i], &y[i]);
			if (i) {
				x[i] -= x[0];
				y[i] -= y[0];
			}
		}
		printf("%d\n", calc(x[1], x[2]) + calc(y[1], y[2]) + 1);
	}
	return 0;
}
