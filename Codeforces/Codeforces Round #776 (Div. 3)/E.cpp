#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, d, a[N];
set < pair <int, int> > s;
set < pair <int, int> > :: iterator it;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &d);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		s.clear();
		a[n+1] = d + 1;
		for (int i = 1; i <= n + 1; i ++) s.insert(make_pair(a[i] - a[i-1], i));
		it = s.begin();
		if ((*it).second == n + 1) it ++;
		int ans = (*it).first;
		int last_seg = d + 1 - a[n];
		for (int i = 1; i <= n; i ++) {
			s.erase(make_pair(a[i] - a[i-1], i));
			s.erase(make_pair(a[i+1] - a[i], i + 1));
			s.insert(make_pair(a[i+1] - a[i-1], i + 1));
			if (i == n) last_seg = a[n+1] - a[n-1];
			it = s.begin();
			if ((*it).second == n + 1) it ++;
			int tmp = (*it).first;
			ans = max(ans, min(tmp, last_seg - 1));
			it = s.end();
			it --;
			int len = (*it).first, j = (*it).second;
			if (j == n + 1) tmp = min(tmp, len - 1);
			else tmp = min(tmp, len / 2);
			ans = max(ans, tmp);
			s.erase(make_pair(a[i+1] - a[i-1], i + 1));
			s.insert(make_pair(a[i] - a[i-1], i));
			s.insert(make_pair(a[i+1] - a[i], i + 1));
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
