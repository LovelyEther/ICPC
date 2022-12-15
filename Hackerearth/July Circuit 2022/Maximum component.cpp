#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree <int, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define N 800800

int n, q, root[N], sub_tree[N];
order_set s;
order_set :: iterator it;

int find_root(int x) {
	return x == root[x] ? x : root[x] = find_root(root[x]);
}

int node_cnt, rt, par[N], son[N][2], sz[N], added[N], f[N];

int new_node() {
	node_cnt ++;
	par[node_cnt] = 0;
	son[node_cnt][0] = son[node_cnt][1] = 0;
	sz[node_cnt] = added[node_cnt] = 0;
	return node_cnt;
}

void push_up(int x) {
	sz[x] = sz[son[x][0]] + sz[son[x][1]] + 1;
}

void push_down(int x) {
	f[x] += added[x];
	if (son[x][0]) added[son[x][0]] += added[x];
	if (son[x][1]) added[son[x][1]] += added[x];
	added[x] = 0;
}

void rot(int x, int d) {
	int y = par[x];
	push_down(y);
	push_down(x);
	int z = par[y];
	if (y == son[z][0]) son[z][0] = x;
	else if (y == son[z][1]) son[z][1] = x;
	par[x] = z;
	son[y][d] = son[x][!d];
	if (son[x][!d]) par[son[x][!d]] = y;
	son[x][!d] = y;
	par[y] = x;
	push_up(y);
	push_up(x);
}

void splay(int x, int tar = 0) {
	while (par[x] != tar) {
		int y = par[x];
		int z = par[y];
		int d = (x == son[y][1]);
		if (z != tar) {
			if (y == son[z][d]) rot(y, d), rot(x, d);
			else rot(x, d), rot(x, !d);
		}
		else {
			rot(x, d);
		}
	}
	if (!tar) rt = x;
}

int find(int k) {
	int x = rt;
	while (1) {
		push_down(x);
		if (sz[son[x][0]] == k - 1) return x;
		if (sz[son[x][0]] >= k) x = son[x][0];
		else k -= sz[son[x][0]] + 1, x = son[x][1];
	}
}

void add(int k, int val) {
	int x = new_node();
	f[x] = val;
	if (node_cnt == 1) {
		push_up(x);
		rt = x;
		return;
	}
	if (k == 1) {
		int y = find(1);
		splay(y);
		son[y][0] = x;
		par[x] = y;
		splay(x);
		added[y] += val;
		return;
	}
	int y = find(k - 1);
	splay(y);
	f[x] += f[y];
	if (!son[y][1]) {
		son[y][1] = x;
		par[x] = y;
		splay(x);
		return;
	}
	int z = son[y][1];
	while (son[z][0]) push_down(z), z = son[z][0];
	push_down(z);
	son[z][0] = x;
	par[x] = z;
	splay(x);
	if (son[x][1]) added[son[x][1]] += val;
}

void del(int k, int val) {
	if (k == 1) {
		int x = find(1);
		splay(x);
		int y = son[x][1];
		if (y) added[y] -= val;
		par[y] = 0;
		son[x][1] = 0;
		push_up(y);
		rt = y;
		return;
	}
	int x = find(k - 1);
	splay(x);
	if (sz[x] == k) {
		int y = son[x][1];
		par[y] = 0;
		son[x][1] = 0;
		push_up(x);
		return;
	}
	int y = find(k + 1);
	splay(y, x);
	int z = son[y][0];
	par[z] = 0;
	son[y][0] = 0;
	added[y] -= val;
	push_up(y);
	push_up(x);
}

int calc(int k) {
	int x = find(k);
	splay(x);
	return f[x];
}

int get_int() {
	int rlt = 0;
	char c;
	while (1) {
		c = getchar();
		if (c < '0' || c > '9') return rlt;
		rlt = rlt * 10 + (c - '0');
	}
}

void put_int(int x) {
	if (!x) {
		putchar('0'); return;
	}
	char buf[11];
	int cnt = 0;
	while (x) buf[cnt++] = '0' + x % 10, x /= 10;
	for (int i = cnt - 1; i >= 0; i --) putchar(buf[i]);
	putchar('\n');
}

int main() {
	n = get_int();
	q = get_int();
	for (int i = 1; i <= n; i ++) root[i] = i, sub_tree[i] = 1;
	for (int i = 1; i <= n; i ++) s.insert(-1);
	for (int i = 1; i <= n; i ++) add(i, 1);
	while (q --) {
		int type, x, y, k;
		type = get_int();
		if (type == 1) {
			x = get_int();
			y = get_int();
			int xx = find_root(x);
			int yy = find_root(y);
			if (xx == yy) continue;
			k = s.order_of_key(-sub_tree[xx]) + 1;
			del(k, sub_tree[xx]);
			s.erase(s.find_by_order(k - 1));
			k = s.order_of_key(-sub_tree[yy]) + 1;
			del(k, sub_tree[yy]);
			s.erase(s.find_by_order(k - 1));
			root[xx] = yy;
			sub_tree[yy] += sub_tree[xx];
			s.insert(-sub_tree[yy]);
			k = s.order_of_key(-sub_tree[yy]) + 1;
			add(k, sub_tree[yy]);
		}
		else {
			k = get_int();
			k ++;
			if (s.size() <= k) {
				put_int(n + (k - 1 == s.size())); continue; // checker error, n is correct
			}
			put_int(calc(k));
		}
	}
	return 0;
}
