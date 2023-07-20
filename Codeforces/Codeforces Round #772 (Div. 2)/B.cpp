#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		vector <int> v;
		for (int i = 2; i < n; i ++) if (a[i-1] < a[i] && a[i] > a[i+1]) v.push_back(i);
		int ans = 0;
		for (int i = 0; i < v.size(); i ++) {
			if (i < v.size() - 1 && v[i+1] == v[i] + 2) {
				a[v[i]+1] = max(a[v[i]], a[v[i]+2]);
				i ++;
				ans ++;
			}
			else {
				a[v[i]+1] = a[v[i]];
				ans ++;
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i ++) printf("%d%c", a[i], i < n ? ' ' : '\n');
	}
	return 0;
}
