#include <bits/stdc++.h>
using namespace std;

#define N 1010

struct ST {
	int n;
	long long mx[N<<3];

	void init(int _n) {
		n = _n;
		for (int i = 1; i <= 4 * n; i ++) mx[i] = 0;
	}

	void push_up(int id) {
		mx[id] = max(mx[id<<1], mx[id<<1^1]);
	}

	void modify(int x, long long val, int l, int r, int id) {
		if (x < l || x > r) return;
		if (l == r) {
			mx[id] = max(mx[id], val); return;
		}
		int m = l + r >> 1;
		modify(x, val, l, m, id << 1);
		modify(x, val, m + 1, r, id << 1 ^ 1);
		push_up(id);
	}

	void modify(int x, long long val) {
		modify(x, val, 1, n, 1);
	}

	long long query(int L, int R, int l, int r, int id) {
		if (R < l || L > r) return 0;
		if (L <= l && r <= R) return mx[id];
		int m = l + r >> 1;
		return max(query(L, R, l, m, id << 1), query(L, R, m + 1, r, id << 1 ^ 1));
	}

	long long query(int l, int r) {
		l = max(l, 1);
		r = min(r, n);
		if (l > r) return 0;
		return query(l, r, 1, n, 1);
	}
} A, B;

int t, n, m, s;
pair <int, int> p[N*N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &m, &s);
		s ++;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				int x;
				scanf("%d", &x);
				p[i*m+j] = make_pair(x, i * m + j);
			}
		}
		A.init(n + m + 7);
		B.init(n + m + 7);
		sort(p, p + n * m);
		long long ans = 0;
		for (int i = 0; i < n * m; i ++) {
			int val = p[i].first;
			int _x = p[i].second / m, _y = p[i].second % m;
			int x = _x + _y + 1, y = _x - _y + m;
			long long cur_max = 0;
			cur_max = max(cur_max, max(A.query(1, x - s), A.query(x + s, n + m)));
			cur_max = max(cur_max, max(B.query(1, y - s), B.query(y + s, n + m)));
			cur_max += val;
			A.modify(x, cur_max);
			B.modify(y, cur_max);
			ans = max(ans, cur_max);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
