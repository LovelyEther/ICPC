#include <bits/stdc++.h>
using namespace std;

#define N 200200
#define M 22

int n, a[N], f[N][M];
vector <int> v;

int calc(int i, int j) {
	int d = 31 - __builtin_clz(j - i + 1);
	return __gcd(f[i][d], f[j-(1<<d)+1][d]) - (j - i + 1);
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), f[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j ++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i ++) f[i][j] = __gcd(f[i][j-1], f[i+(1<<j-1)][j-1]);
	}
	int ans = 0, last = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) {
			v.push_back(++ ans);
			last = i;
			continue;
		}
		if (calc(last + 1, i) > 0) {
			v.push_back(ans);
			continue;
		}
		int st = last + 1, en = i;
		while (en - st > 1) {
			int mid = st + en >> 1;
			if (calc(mid, i) <= 0) st = mid;
			else en = mid;
		}
		if (calc(st, i) == 0) ans ++, last = i;
		v.push_back(ans);
	}
	for (int i = 0; i < v.size(); i ++) printf("%d%c", v[i], i < v.size() - 1 ? ' ' : '\n');
	return 0;
}
