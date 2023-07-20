#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, w, m, f[N];
char s[N];
vector <int> v[11];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%s %d %d", s + 1, &w, &m);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i ++) f[i] = f[i-1] + (s[i] - '0');
		for (int i = 0; i < 9; i ++) v[i].clear();
		for (int i = 1; i + w - 1 <= n; i ++) v[(f[i+w-1] - f[i-1])%9].push_back(i);
		while (m --) {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			int c = (f[r] - f[l-1]) % 9;
			int L1 = n + 1, L2 = n + 1;
			for (int i = 0; i < 9; i ++) if (v[i].size() > 0) {
				for (int j = 0; j < 9; j ++) if (v[j].size() > 0) {
					if ((i * c + j) % 9 != k) continue;
					if (i == j && v[i].size() == 1) continue;
					int l1 = v[i][0], l2 = i == j ? v[i][1] : v[j][0];
					if (L1 > l1) L1 = l1, L2 = l2;
					else if (L1 == l1 && L2 > l2) L2 = l2;
				}
			}
			if (L1 == n + 1) L1 = -1, L2 = -1;
			printf("%d %d\n", L1, L2);
		}
	}
	return 0;
}
