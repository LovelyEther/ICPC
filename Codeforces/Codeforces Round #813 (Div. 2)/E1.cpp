#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, l, r, f[N];
vector <int> v[N], w[N];

int counts(vector <int> &v, int st, int en) {
	int pst = lower_bound(v.begin(), v.end(), st) - v.begin();
	int pen = lower_bound(v.begin(), v.end(), en + 1) - v.begin();
	return max(0, pen - pst);
}

long long solve(int l, int r) {
	long long rlt = 0;
	for (int k = l + 2; k <= r; k ++) {
		f[k] = 0;
		int cnt = counts(v[k], l, k - 1);
		if (cnt >= 2) f[k] = cnt * (cnt - 1) / 2;
		for (auto j: v[k]) if (j < l && k - j < j) {
			int st = max(l + 1, k - j + 2) / 2, en = (j - 1) / 2;
			f[k] += counts(w[k], st, en);
		}
		for (auto i: v[k]) if (l <= i) {
			int st = (max(i, k - i) + 2) / 2, en = (k - 1) / 2;
			f[k] += counts(w[k], st, en);
		}
		for (auto i2: w[k]) if (l <= 2 * i2) {
			int i = i2 * 2;
			int st = (max(i, k - i) + 2) / 2, en = (k - 1) / 2;
			f[k] += counts(w[k], st, en);
		}
		rlt += f[k];
	}
	int cnt = r - l + 1;
	return 1ll * cnt * (cnt - 1) * (cnt - 2) / 6 - rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int i = 1; i < N; i ++) {
		for (int j = i; j < N; j += i) v[j].push_back(i);
	}
	for (int i = 1; i < N; i ++) {
		for (auto x: v[i]) if (i % (2 * x) > 0) w[i].push_back(x);
	}
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &l, &r);
		printf("%I64d\n", solve(l, r));
	}
	return 0;
}
