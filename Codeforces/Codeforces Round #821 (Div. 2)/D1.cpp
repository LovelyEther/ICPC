#include <bits/stdc++.h>
using namespace std;

#define N 5050

int t, n, x, y;
char A[N], B[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &x, &y);
		scanf("%s %s", A + 1, B + 1);
		vector <int> v;
		for (int i = 1; i <= n; i ++) if (A[i] != B[i]) v.push_back(i);
		if (v.size() % 2) puts("-1");
		else {
			if (v.size() == 2 && v[0] + 1 == v[1]) {
				int ans = x;
				if (n > 4) ans = min(ans, 2 * y);
				else if (n == 4) {
					if (v[0] != 2) ans = min(ans, 2 * y);
					else {
						ans = min(ans, 3 * y);
					}
				}
				printf("%d\n", ans);
			}
			else {
				printf("%I64d\n", 1ll * y * v.size() / 2);
			}
		}
	}
	return 0;
}
