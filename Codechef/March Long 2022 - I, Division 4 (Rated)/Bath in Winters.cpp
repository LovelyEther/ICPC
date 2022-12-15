#include <bits/stdc++.h>
using namespace std;

int t, x, y;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &x, &y);
		printf("%d\n", x / (2 * y));
	}
	return 0;
}
