#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &a, &b);
		if (a >= n) {
			puts("1"); continue;
		}
		if (a <= b) {
			puts("-1"); continue;
		}
		printf("%d\n", 1 + (n - a + (a - b) - 1) / (a - b) * 2);
	}
	return 0;
}