#include <bits/stdc++.h>
using namespace std;

#define N 5050

const long long inf = 1ll << 60;

int t, n, x, y;
char A[N], B[N];

long long calc(int l, int r) {
	return min(1ll * x * (r - l), 1ll * y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &x, &y);
		scanf("%s %s", A + 1, B + 1);
		vector <int> v;
		for (int i = 1; i <= n; i ++) if (A[i] != B[i]) v.push_back(i);
		if (v.size() % 2) puts("-1");
		else {
			if (x >= y) {
				if (v.size() == 2 && v[0] + 1 == v[1]) {
					printf("%d\n", min(x, 2 * y));
				}
				else {
					printf("%I64d\n", 1ll * y * v.size() / 2);
				}
			}
			else {
				if (v.size() == 0) {
					puts("0"); continue;
				}
				vector <long long> f;
				for (int i = 0; i < v.size(); i ++) {
					if (!i) {
						f.push_back(0);
						continue;
					}
					if (i == 1) {
						f.push_back(calc(v[0], v[1]));
						continue;
					}
					long long tmp = f[i-1];
					if (i % 2 == 0) {
						tmp = min(tmp, f[i-2] + calc(v[i-1], v[i]));
					}
					else {
						tmp += y;
						tmp = min(tmp, f[i-2] + calc(v[i-1], v[i]));
					}
					f.push_back(tmp);
				}
				printf("%I64d\n", f[f.size()-1]);
			}
		}
	}
	return 0;
}
