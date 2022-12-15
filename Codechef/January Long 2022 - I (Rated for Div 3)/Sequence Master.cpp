#include <bits/stdc++.h>
using namespace std;

#define N 200200

long long add[N<<2], sum[N<<2];

void add_range(int l, int r, int id, long long val) {
	sum[id] += val * (r - l + 1);
	add[id] += val;
}

void push_down(int l, int r, int id) {
	int m = l + r >> 1;
	add_range(l, m, id << 1, add[id]);
	add_range(m + 1, r, id << 1 ^ 1, add[id]);
	add[id] = 0;
}

void push_up(int id) {
	sum[id] = sum[id<<1] + sum[id<<1^1];
}

void modify(int L, int R, long long val, int l, int r, int id) {
	if (L > r || R < l) return;
	if (L <= l && r <= R) {
		add_range(l, r, id, val); return;
	}
	int m = l + r >> 1;
	push_down(l, r, id);
	modify(L, R, val, l, m, id << 1);
	modify(L, R, val, m + 1, r, id << 1 ^ 1);
	push_up(id);
}

long long query(int L, int R, int l, int r, int id) {
	if (L > r || R < l) return 0;
	if (L <= l && r <= R) return sum[id];
	push_down(l, r, id);
	int m = l + r >> 1;
	return query(L, R, l, m, id << 1) + query(L, R, m + 1, r, id << 1 ^ 1);
}

int n, q, a[N];
long long f[N];
set <int> s[N];
set <int> :: iterator it;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		int j = s[a[i]].empty() ? 0 : *s[a[i]].rbegin();
		f[i] = f[i-1] + i - j;
		s[a[i]].insert(i);
		modify(i, i, f[i], 1, n, 1);
	}
	while (q --) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (a[x] == y) continue;
			it = s[a[x]].find(x);
			int prv = 0, nxt = n + 1;
			if (it != s[a[x]].begin()) {
				it --;
				prv = *it;
				it ++;
			}
			it ++;
			if (it != s[a[x]].end()) nxt = *it;
			it --;
			s[a[x]].erase(it);
			modify(x, nxt - 1, -(x - prv), 1, n, 1);
			a[x] = y;
			s[a[x]].insert(x);
			it = s[a[x]].find(x);
			prv = 0, nxt = n + 1;
			if (it != s[a[x]].begin()) {
				it --;
				prv = *it;
				it ++;
			}
			it ++;
			if (it != s[a[x]].end()) nxt = *it;
			it --;
			modify(x, nxt - 1, x - prv, 1, n, 1);
		}
		else {
			int k;
			scanf("%d", &k);
			printf("%I64d\n", query(1, k, 1, n, 1));
		}
	}
	return 0;
}
