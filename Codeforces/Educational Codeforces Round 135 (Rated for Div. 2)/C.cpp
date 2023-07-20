#include <bits/stdc++.h>
using namespace std;

int t, n;
multiset <int> A, B, AA, BB;
multiset <int> :: iterator it, jt;

int func(int x) {
	int rlt = 0;
	while (x > 0) rlt ++, x /= 10;
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		A.clear(), B.clear();
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			A.insert(x);
		}
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			it = A.find(x);
			if (it != A.end()) {
				A.erase(it);
			}
			else {
				B.insert(x);
			}
		}
		int ans = 0;
		AA.clear(), BB.clear();
		for (it = A.begin(); it != A.end(); it ++) {
			int x = *it;
			if (x >= 10) x = func(x), ans ++;
			AA.insert(x);
		}
		for (it = B.begin(); it != B.end(); it ++) {
			int x = *it;
			if (x >= 10) x = func(x), ans ++;
			jt = AA.find(x);
			if (jt != AA.end()) {
				AA.erase(jt);
			}
			else {
				BB.insert(x);
			}
		}
		for (it = AA.begin(); it != AA.end(); it ++) if (*it != 1) ans ++;
		for (it = BB.begin(); it != BB.end(); it ++) if (*it != 1) ans ++;
		printf("%d\n", ans);
	}
	return 0;
}
