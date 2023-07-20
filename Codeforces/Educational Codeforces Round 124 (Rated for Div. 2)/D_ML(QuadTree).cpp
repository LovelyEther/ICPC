#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define M 2000000

struct NODE {
	int index;
	int minx, maxx, miny, maxy;
	NODE *left, *right;
	NODE(int _idx = 0, int _x1 = 0, int _x2 = 0, int _y1 = 0, int _y2 = 0) {
		index = _idx;
		minx = _x1, maxx = _x2;
		miny = _y1, maxy = _y2;
		left = NULL;
		right = NULL;
	}
};

void add(int x, int y, int index, NODE* rt, int dp) {
	if (x < rt -> minx || x > rt -> maxx || y < rt -> miny || y > rt -> maxy) return;
	if (rt -> minx == rt -> maxx && rt -> miny == rt -> maxy) {
		rt -> index = index; return;
	}
	if (!rt -> left) {
		if (dp & 1) {
			int midx = (rt -> minx + rt -> maxx) >> 1;
			rt -> left = new NODE(0, rt -> minx, midx, rt -> miny, rt -> maxy);
			rt -> right = new NODE(0, midx + 1, rt -> maxx, rt -> miny, rt -> maxy);
		}
		else {
			int midy = (rt -> miny + rt -> maxy) >> 1;
			rt -> left = new NODE(0, rt -> minx, rt -> maxx, rt -> miny, midy);
			rt -> right = new NODE(0, rt -> minx, rt -> maxx, midy + 1, rt -> maxy);
		}
	}
	add(x, y, index, rt -> left, dp + 1);
	add(x, y, index, rt -> right, dp + 1);
	rt -> index = max(rt -> left -> index, rt -> right -> index);
}

int calc(int stx, int enx, int sty, int eny, NODE* rt) {
	if (enx < rt -> minx || stx > rt -> maxx || eny < rt -> miny || sty > rt -> maxy) return 0;
	if (stx <= rt -> minx && rt -> maxx <= enx && sty <= rt -> miny && rt -> maxy <= eny) return rt -> index;
	if (rt -> left) {
		int tmp = calc(stx, enx, sty, eny, rt -> left);
		if (tmp) return tmp;
	}
	if (rt -> right) {
		int tmp = calc(stx, enx, sty, eny, rt -> right);
		if (tmp) return tmp;
	}
	return 0;
}

pii transfer(pii p) {
	return make_pair(p.first - p.second, p.first + p.second);
}

#define N 200200

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
map <pii, int> mp;
pii p[N], q[N*4];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &p[i].first, &p[i].second);
		mp[p[i]] = 1;
	}
	for (int i = 1; i <= n; i ++) {
		int x = p[i].first, y = p[i].second;
		for (int k = 0; k < 4; k ++) {
			int xx = x + dx[k], yy = y + dy[k];
			if (!mp.count(make_pair(xx, yy))) q[++m] = make_pair(xx, yy);
		}
	}
	NODE* root = new NODE(0, -M, M, -M, M);
	for (int i = 1; i <= m; i ++) {
		pii tmp = transfer(q[i]);
		add(tmp.first, tmp.second, i, root, 0);
	}
	for (int i = 1; i <= n; i ++) {
		pii tmp = transfer(p[i]);
		int x = tmp.first, y = tmp.second;
		int st = 0, en = M;
		while (en - st > 1) {
			int md = st + en >> 1;
			if (calc(x - md, x + md, y - md, y + md, root)) en = md;
			else st = md;
		}
		int id = calc(x - en, x + en, y - en, y + en, root);
		printf("%d %d\n", q[id].first, q[id].second);
	}
	return 0;
}
