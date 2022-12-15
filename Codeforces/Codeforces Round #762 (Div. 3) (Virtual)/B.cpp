#include <bits/stdc++.h>
using namespace std;

const double ep = 1e-8;

int t, n;

int rt(int n, int d) {
	int x = pow(n, 1.0 / d);
	long long n1 = 1, n2 = 1;
	while (d --) n1 *= x, n2 *= x + 1;
	return n2 <= n ? x + 1 : x;
}

int main() {
	//freopen("b.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		printf("%d\n", rt(n, 2) + rt(n, 3) - rt(n, 6));
	}
	return 0;
}
