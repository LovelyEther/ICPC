#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], b[N], c[N];
map < pair <int, int>, int > mp;

int main() {
	//freopen("b.in", "r", stdin);
	c[0] = 2e9;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		mp.clear();
		int mn = 2e9, mx = 0;
		int mnid1 = 0, mnid2 = 0;
		int mxid1 = 0, mxid2 = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			pair <int, int> pii = make_pair(a[i], b[i]);
			if (!mp.count(pii)) mp[pii] = c[i];
			else mp[pii] = min(mp[pii], c[i]);
			if (a[i] < mn) {
				mnid2 = 0;
				mnid1 = i;
			}
			else if (a[i] == mn) {
				if (c[i] < c[mnid1]) mnid2 = mnid1, mnid1 = i;
				else if (c[i] < c[mnid2]) mnid2 = i;
			}
			if (b[i] > mx) {
				mxid2 = 0;
				mxid1 = i;
			}
			else if (b[i] == mx) {
				if (c[i] < c[mxid1]) mxid2 = mxid1, mxid1 = i;
				else if (c[i] < c[mxid2]) mxid2 = i;
			}
			mn = a[mnid1], mx = b[mxid1];
			int ans = c[mnid1] + c[mxid1];
			pii = make_pair(a[mnid1], b[mxid1]);
			if (mp.count(pii)) ans = min(ans, mp[pii]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
