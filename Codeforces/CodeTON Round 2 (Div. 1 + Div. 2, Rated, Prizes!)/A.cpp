#include <bits/stdc++.h>
using namespace std;

#define N 55

int t, n, m;
char a[N], b[N];

bool good() {
	for (int i = m - 1; i > 0; i --) if (b[i] != a[n-m+i]) return 0;
	for (int i = n - m; i >= 0; i --) if (a[i] == b[0]) return 1;
	return 0;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %s %s", &n, &m, a, b);
		if (good()) puts("YES");
		else puts("NO");
	}
	return 0;
}
