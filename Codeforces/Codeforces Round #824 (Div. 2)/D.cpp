#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define K 22

int n, k, a[N][K], c[K], cnt[N];
long long val[N];
map <long long, int> mp;

long long get_val(int* a) {
	long long rlt = 0;
	for (int i = 1; i <= k; i ++) rlt = rlt * 3 + a[i];
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) scanf("%d", &a[i][j]);
		val[i] = get_val(a[i]);
		mp[val[i]] = i;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			for (int p = 1; p <= k; p ++) {
				c[p] = a[i][p] == a[j][p] ? a[i][p] : 3 - a[i][p] - a[j][p];
			}
			long long tmp = get_val(c);
			if (mp.count(tmp)) cnt[mp[tmp]] ++;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
	printf("%I64d\n", ans);
	return 0;
}
