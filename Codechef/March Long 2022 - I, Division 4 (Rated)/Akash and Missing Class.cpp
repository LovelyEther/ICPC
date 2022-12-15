#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		printf("%d\n", n / 7 + (n % 7 >= 6));
	}
	return 0;
}
