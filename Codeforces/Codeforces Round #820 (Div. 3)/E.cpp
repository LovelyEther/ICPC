#include <bits/stdc++.h>
using namespace std;

long long query(long long a, long long b) {
	printf("? %I64d %I64d\n", a, b);
	fflush(stdout);
	long long c;
	scanf("%I64d", &c);
	return c;
}

void finish(long long n) {
	printf("! %I64d\n", n);
	fflush(stdout);
}

void solve() {
	for (int i = 2; i <= 24; i ++) {
		long long x = query(1, i);
		long long y = query(i, 1);
		if (x == -1 || y == -1) {
			finish(i - 1); return;
		}
		if (x != y) {
			finish(x + y); return;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int tc = 50; tc; tc --) solve();
	return 0;
}
