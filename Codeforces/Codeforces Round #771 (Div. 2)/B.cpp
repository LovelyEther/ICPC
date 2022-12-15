#include <bits/stdc++.h>
using namespace std;

int t, n;
vector <int> v[2], w[2];

bool sorted(vector <int> v) {
	for (int i = 0; i + 1 < v.size(); i ++) if (v[i] > v[i+1]) return 0;
	return 1;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		v[0].clear();
		v[1].clear();
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			v[x&1].push_back(x);
		}
		if (sorted(v[0]) && sorted(v[1])) puts("Yes");
		else puts("No");
	}
	return 0;
}
