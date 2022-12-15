#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, x, a[N];
set <int> s;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &x), a[x] = i;
		s.clear();
		s.insert(a[1]);
		for (int i = 2; i <= n; i ++) {
			set <int> :: iterator it = s.lower_bound(a[i]);
			if (it != s.end()) {
				while (it != s.end()) {
					x = *it;
					it ++;
					s.erase(x);
				}
				s.insert(x);
			}
			else s.insert(a[i]);
		}
		printf("%d\n", s.size());
	}
	return 0;
}
