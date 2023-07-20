#include <bits/stdc++.h>
using namespace std;

int t, n, mn, mx;
char s[200200];

bool cmp(int i, int j) {
	if (s[1] == mn) return s[i] < s[j];
	else return s[i] > s[j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		mn = min(s[1], s[n]);
		mx = max(s[1], s[n]);
		vector <int> ans;
		for (int i = 2; i < n; i ++) if (mn <= s[i] && s[i] <= mx) ans.push_back(i);
		printf("%d %d\n", mx - mn, ans.size() + 2);
		sort(ans.begin(), ans.end(), cmp);
		printf("1 ");
		for (int i = 0; i < ans.size(); i ++) printf("%d ", ans[i]);
		printf("%d\n", n);
	}
	return 0;
}
