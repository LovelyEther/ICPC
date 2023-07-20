#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		printf("%d\n", (n - 6) / 3);
	}
	return 0;
}
