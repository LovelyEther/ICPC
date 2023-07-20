#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n & 1) {
			printf("1 ");
			for (int i = n - 2; i > 1; i --) printf("%d ", i);
		}
		else {
			for (int i = n - 2; i >= 1; i --) printf("%d ", i);
		}
		printf("%d %d\n", n - 1, n);
	}
	return 0;
}
