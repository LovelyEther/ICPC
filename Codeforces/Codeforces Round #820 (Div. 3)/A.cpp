#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &a, &b, &c);
		int A = a - 1;
		int B = abs(b - c) + c - 1;
		if (A < B) puts("1");
		else if (A > B) puts("2");
		else puts("3");
	}
	return 0;
}
