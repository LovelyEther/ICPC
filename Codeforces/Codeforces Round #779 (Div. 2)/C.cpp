#include <bits/stdc++.h>
using namespace std;

#define N 500500

int t, n, a[N], b[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int j = -1, cnt = 0;
		for (int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
			if (a[i] == 1) j = i, cnt ++;
		}
		if (j == -1 || cnt > 1) {
			puts("NO"); continue;
		}
		for (int i = 0; i < n; i ++) b[i] = a[(i+j)%n];
		bool valid = true;
		for (int i = 1; i < n; i ++) if (b[i] > b[i-1] + 1) valid = false;
		if (valid) puts("YES");
		else puts("NO");
	}
	return 0;
}
