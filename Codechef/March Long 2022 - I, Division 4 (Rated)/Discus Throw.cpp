#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", max(a, max(b, c)));
	}
	return 0;
}
