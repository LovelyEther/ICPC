#include <bits/stdc++.h>
using namespace std;

#define N 2020

int t, n, a[N], b[N], s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = n; i >= 1; i --) {
			if (a[i] == i) {
				s[i] = 0; continue;
			}
			int p = 0;
			for (int j = 1; j <= i; j ++) if (a[j] == i) p = j;
			s[i] = p;
			for (int j = 1; j <= p; j ++) b[j] = a[j];
			for (int j = 1; j <= i - p; j ++) a[j] = a[j+p];
			for (int j = 1; j <= p; j ++) a[i-p+j] = b[j];
		}
		for (int i = 1; i <= n; i ++) printf("%d%c", s[i], i < n ? ' ' : '\n');
	}
	return 0;
}
