#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, k, m, x, y, mx_b, a[N];
map <int, int> mp;
vector <int> v[N];
vector <int> ans;

bool solve(vector <int> A, vector <int> B, int bit) {
	if (A.size() == 0 || B.size() == 0) return 0;
	if (bit == -1) {
		x = A[0], y = B[0]; return 1;
	}
	vector <int> aa, ab, ba, bb;
	for (int i = 0; i < A.size(); i ++) {
		if (a[A[i]] & (1 << bit)) ab.push_back(A[i]);
		else aa.push_back(A[i]);
	}
	for (int i = 0; i < B.size(); i ++) {
		if (a[B[i]] & (1 << bit)) bb.push_back(B[i]);
		else ba.push_back(B[i]);
	}
	if (!(k & (1 << bit))) {
		if (aa.size() > 0 && bb.size() > 0) {
			x = aa[0], y = bb[0]; return 1;
		}
		if (ab.size() > 0 && ba.size() > 0) {
			x = ab[0], y = ba[0]; return 1;
		}
	}
	if (solve(aa, bb, bit - 1)) return 1;
	if (solve(ab, ba, bit - 1)) return 1;
	return 0;
}

bool conq(vector <int> w) {
	vector <int> A, B;
	for (int i = 0; i < w.size(); i ++) {
		if (a[w[i]] & (1 << mx_b)) B.push_back(w[i]);
		else A.push_back(w[i]);
	}
	return solve(A, B, mx_b - 1);
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	if (!k) {
		printf("%d\n", n);
		for (int i = 1; i <= n; i ++) printf("%d%c", i, i < n ? ' ' : '\n');
		return 0;
	}
	mx_b = 0;
	for (int j = 0; j < 30; j ++) if (k & (1 << j)) mx_b = j;
	for (int i = 1; i <= n; i ++) {
		int cls = a[i] >> mx_b + 1;
		if (!mp.count(cls)) mp[cls] = ++ m;
		v[mp[cls]].push_back(i);
	}
	for (int i = 1; i <= m; i ++) {
		if (conq(v[i])) ans.push_back(x), ans.push_back(y);
		else ans.push_back(v[i][0]);
	}
	if (ans.size() == 1) {
		puts("-1"); return 0;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) printf("%d%c", ans[i], i < ans.size() - 1 ? ' ' : '\n');
	return 0;
}
