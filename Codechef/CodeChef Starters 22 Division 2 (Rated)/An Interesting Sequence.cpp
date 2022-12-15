#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		printf("%d\n", 31 - __builtin_clz(n & -n));
	}
	return 0;
}
