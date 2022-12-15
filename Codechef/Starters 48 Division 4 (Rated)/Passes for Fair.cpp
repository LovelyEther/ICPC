#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		if (n + 1 <= k) puts("YES");
		else puts("NO");
	}
	return 0;
}
