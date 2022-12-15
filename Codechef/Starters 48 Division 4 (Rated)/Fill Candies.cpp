#include <bits/stdc++.h>
using namespace std;

int t, n, k, m;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &k, &m);
		printf("%d\n", (n + k * m - 1) / (k * m));
	}
	return 0;
}
