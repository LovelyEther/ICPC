#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, x, f[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) f[i] = 0;
		for (int i = 1; i <= n; i ++) scanf("%d", &x), f[x] ++;
		for (int i = 1; i <= n; i ++) f[i] += f[i-1];
		int st = 0, en = n;
		while (en - st > 1) {
			int md = st + en >> 1;
			bool flag = true;
			for (int i = 1; i * md <= n; i ++) {
				if (f[i] > i * md) flag = false;
			}
			if (flag) en = md;
			else st = md;
		}
		printf("%d\n", en);
	}
	return 0;
}
