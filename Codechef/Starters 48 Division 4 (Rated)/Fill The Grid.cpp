#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		if (n % 2 == 0 && m % 2 == 0) puts("0");
		else if (n % 2 == 0) printf("%d\n", n);
		else if (m % 2 == 0) printf("%d\n", m);
		else printf("%d\n", n + m - 1);
	}
	return 0;
}
