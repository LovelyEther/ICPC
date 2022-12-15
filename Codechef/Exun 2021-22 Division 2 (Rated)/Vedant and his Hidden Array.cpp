#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		if (n == 1) {
			puts(x & 1 ? "Odd" : "Even"); continue;
		}
		if (x & 1) {
			puts(n & 1 ? "Odd" : "Even");
		}
		else {
			puts("Impossible");
		}
	}
	return 0;
}
