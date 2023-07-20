#include <bits/stdc++.h>
using namespace std;

int t, n, k, x;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &k, &x);
		if (x != 1) {
			puts("YES");
			printf("%d\n", n);
			for (int i = 1; i <= n; i ++) printf("1%c", i < n ? ' ' : '\n');
			continue;
		}
		if (k == 1) {
			puts("NO"); continue;
		}
		if (k == 2) {
			if (n % 2 == 1) puts("NO");
			else {
				puts("YES");
				printf("%d\n", n / 2);
				for (int i = 1; i <= n / 2; i ++) printf("2%c", i < n / 2 ? ' ' : '\n');
			}
			continue;
		}
		vector <int> v;
		if (n & 1) v.push_back(3), n -= 3;
		while (n > 0) v.push_back(2), n -= 2;
		puts("YES");
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i ++) printf("%d%c", v[i], i < v.size() - 1 ? ' ' : '\n');
	}
	return 0;
}
