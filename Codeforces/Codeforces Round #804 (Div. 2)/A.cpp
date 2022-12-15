#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n & 1) puts("-1");
		else printf("%d %d %d\n", 0, n / 2, n / 2);
	}
	return 0;
}
