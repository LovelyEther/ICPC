#include <bits/stdc++.h>
using namespace std;

long long calc(long long n) {
	if (!n) return 0;
	long long x = sqrt(n);
	long long rlt = (x - 1) * 3 + 1;
	if (n >= x * x + x) rlt ++;
	if (n >= x * x + 2 * x) rlt ++;
	return rlt;
}

int t;
long long l, r;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%I64d %I64d", &l, &r);
		printf("%I64d\n", calc(r) - calc(l - 1));
	}
	return 0;
}
