#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], b[N];
char A[N], B[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s %s", &n, A, B);
		for (int i = 0; i < n; i ++) a[i] = A[i] - '0', b[i] = B[i] - '0';
		vector <int> ans;
		for (int i = 0; i < n; i ++) {
			if (a[i] & 1) {
				b[i] ^= 1;
				ans.push_back(i + 1);
			}
		}
		bool yes = true;
		for (int i = 1; i < n; i ++) if (b[i] != b[i-1]) yes = false;
		if (!yes) {
			puts("NO"); continue;
		}
		puts("YES");
		if (ans.size() % 2 != b[0]) {
			printf("%d\n", ans.size() + 3);
			for (int i = 0; i < ans.size(); i ++) printf("%d %d\n", ans[i], ans[i]);
			printf("%d %d\n", 1, 1);
			printf("%d %d\n", 2, n);
			printf("%d %d\n", 1, n);
		}
		else {
			printf("%d\n", ans.size());
			for (int i = 0; i < ans.size(); i ++) printf("%d %d\n", ans[i], ans[i]);
		}
	}
	return 0;
}
