#include <bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, k;
pair <int, int> p[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &p[i].first);
		for (int i = 1; i <= n; i ++) scanf("%d", &p[i].second);
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i ++) {
			if (p[i].first > k) break;
			k += p[i].second;
		}
		printf("%d\n", k);
	}
	return 0;
}
