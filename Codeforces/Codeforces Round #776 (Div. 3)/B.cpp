#include <bits/stdc++.h>
using namespace std;

int t, l, r, a, ans;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &l, &r, &a);
		ans = r / a + r % a;
		if (l < r / a * a) ans = max(ans, r / a - 1 + a - 1);
		printf("%d\n", ans);
	}
	return 0;
}
