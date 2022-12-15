#include <bits/stdc++.h>
using namespace std;

int t, x, y, a, b;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		printf("%d\n", (x != a && x != b) + (y != a && y != b));
	}
	return 0;
}
