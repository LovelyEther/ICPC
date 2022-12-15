#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, k, f[N];
vector <int> v[N];

int dfs(int x) {
	int xor_sum = 0;
	for (int i = 0; i < v[x].size(); i ++) {
		xor_sum ^= dfs(v[x][i]);
	}
	if (k) {
		f[x] = xor_sum ^ 1;
		k --;
	}
	else {
		f[x] = xor_sum;
	}
	return xor_sum ^ f[x];
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int i = 2; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		dfs(1);
		for (int i = 1; i <= n; i ++) printf("%d", f[i]); puts("");
	}
	return 0;
}
