#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, a[N][N], b[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
	}
	for (int j = 1; j <= m; j ++) {
		for (int i = 1; i <= n; i ++) b[j] = max(b[j], a[i][j]);
	}
	int mxcnt = 0;
	long long mxsum = 0;
	int id = 0;
	for (int i = 1; i <= n; i ++) {
		int cnt = 0;
		long long sum = 0;
		for (int j = 1; j <= m; j ++) {
			if (a[i][j] == b[j]) cnt ++;
			sum += a[i][j];
		}
		if (cnt > mxcnt) {
			mxcnt = cnt, mxsum = sum, id = i;
		}
		else if (cnt == mxcnt && sum > mxsum) {
			mxsum = sum, id = i;
		}
	}
	printf("%d\n", id);
	return 0;
}
