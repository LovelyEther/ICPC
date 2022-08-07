#include <bits/stdc++.h>
using namespace std;

#define N 300300

const int mod = 1e9 + 7;

int n, f[N][5];
vector <int> v[N];
long long ans;

void dfs(int x, int p = 0) {
	f[x][0] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y == p) continue;
		dfs(y, x);
		for (int j = 0; j <= 3; j ++) f[x][j+1] += f[y][j];
	}
	ans = (ans + f[x][4]) % mod;
	long long tw = 0;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y == p) continue;
		ans = (ans + f[x][3] - f[y][2]) % mod;
		tw += 1ll * f[y][1] * (f[x][2] - f[y][1]);
	}
	ans = (ans + tw / 2) % mod;
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
