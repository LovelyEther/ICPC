#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], id[N];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			id[i] = i;
		}
		sort(id + 1, id + n + 1, cmp);
		printf("%d %d\n", id[1], id[n]);
	}
	return 0;
}
