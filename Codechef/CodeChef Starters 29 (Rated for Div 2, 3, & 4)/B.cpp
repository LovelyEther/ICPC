#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		printf("%d\n", n * 2 + m * 4);
	}
	return 0;
}
