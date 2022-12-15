#include <bits/stdc++.h>
using namespace std;

int t, n;

int solve(int n) {
	if (n < 21) return -1;
	if (n == 21) return 1;
	if (n < 30) return -1;
	if (n <= 40) return 2;
	n -= 30;
	if (n % 14 > 10) return -1;
	return n / 14 + 2;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}
