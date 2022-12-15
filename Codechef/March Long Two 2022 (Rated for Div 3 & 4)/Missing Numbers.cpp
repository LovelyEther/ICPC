#include <bits/stdc++.h>
using namespace std;

int t, x[4], a, b;
multiset <int> s, ss;

bool ok() {
	if (a <= 0 || a > 10000 || b <= 0 || b > 10000) return 0;
	ss.clear();
	ss.insert(a + b);
	ss.insert(a - b);
	ss.insert(a * b);
	ss.insert(a / b);
	return ss == s;
}

void solve() {
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 4; j ++) if (i != j) {
			a = (x[i] + x[j]) / 2;
			b = (x[i] - x[j]) / 2;
			if (ok()) {
				printf("%d %d\n", a, b); return;
			}
		}
	}
	printf("%d %d\n", -1, -1);
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		s.clear();
		for (int i = 0; i < 4; i ++) scanf("%d", &x[i]), s.insert(x[i]);
		solve();
	}
	return 0;
}
