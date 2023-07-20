#include <bits/stdc++.h>
using namespace std;

#define N 505

int t, n, a[N];

bool sorted() {
	for (int i = 1; i <= n; i ++) if (a[i] != i) return 0;
	return 1;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		if (sorted()) {
			for (int i = 1; i <= n; i ++) printf("%d ", a[i]);
			puts("");
			continue;
		}
		int p = 0, st = 0, en = 0;
		for (int i = 1; i <= n; i ++) {
			st = i;
			if (a[i] != i) {
				p = i; break;
			}
		}
		for (int j = 1; j <= n; j ++) if (a[j] == p) en = j;
		for (int i = 1; i < st; i ++) printf("%d ", a[i]);
		for (int i = en; i >= st; i --) printf("%d ", a[i]);
		for (int i = en + 1; i <= n; i ++) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}
