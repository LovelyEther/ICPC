#include <bits/stdc++.h>
using namespace std;

int t, n, a[100100];

bool yes() {
	bool one = 0;
	for (int i = 1; i <= n; i ++) if (a[i] == 1) one = 1;
	if (one) {
		if (a[1] == 0) return 0;
		for (int i = 1; i < n; i ++) if (a[i+1] == a[i] + 1) return 0;
		return 1;
	}
	return 1;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		if (yes()) puts("YES");
		else puts("NO");
	}
	return 0;
}
