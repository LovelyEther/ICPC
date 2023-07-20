#include <bits/stdc++.h>
using namespace std;

#define N 7

int t, x[N], y[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		for (int i = 0; i < 3; i ++) scanf("%d %d", &x[i], &y[i]);
		int ans = 0;
		for (int i = 0; i < 3; i ++) if (y[i] == y[(i+1)%3] && y[(i+2)%3] < y[i]) ans += abs(x[i] - x[(i+1)%3]);
		printf("%d\n", ans);
	}
	return 0;
}
