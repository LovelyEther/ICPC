#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, x, a[N];
map < vector <int>, int > mp;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		vector <int> p, q;
		for (int i = 2; i * i <= x; i ++) if (x % i == 0) {
			p.push_back(i);
			int ord = 0;
			while (x % i == 0) x /= i, ord ++;
			q.push_back(ord);
		}
		if (x > 1) {
			p.push_back(x);
			q.push_back(1);
		}
		m = q.size();
		vector <int> rivet, tmp;
		for (int j = 0; j < m; j ++) rivet.push_back(0), tmp.push_back(0);
		mp.clear();
		mp[rivet] = 1;
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < m; j ++) {
				tmp[j] -= q[j];
				while (a[i] % p[j] == 0) a[i] /= p[j], tmp[j] ++;
			}
			if (a[i] > 1) {
				mp.clear();
				mp[rivet] = 1;
				tmp = rivet;
				continue;
			}
			ans += mp[tmp];
			mp[tmp] ++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
