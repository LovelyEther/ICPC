#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], cnt[N];
long long ans[N];
priority_queue <int> pq;

int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i ++) cnt[i] = 0;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), cnt[a[i]] ++;
		sort(a + 1, a + n + 1);
		for (int i = 0; i <= n; i ++) ans[i] = -1;
		ans[0] = cnt[0];
		while (!pq.empty()) pq.pop();
		for (int i = 1; i < cnt[0]; i ++) pq.push(0);
		long long inc = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt[i-1] <= 0) {
				if (pq.empty()) break;
				int x = pq.top(); pq.pop();
				inc += i - 1 - x;
			}
			ans[i] = inc + cnt[i];
			for (int j = 1; j < cnt[i]; j ++) pq.push(i);
		}
		for (int i = 0; i <= n; i ++) printf("%I64d%c", ans[i], i < n ? ' ' : '\n');
	}
	return 0;
}
