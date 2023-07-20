#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int ans = 0;
		while (n --) {
			int x;
			scanf("%d", &x);
			ans |= x;
		}
		printf("%d\n", ans);
	}
	return 0;
}
