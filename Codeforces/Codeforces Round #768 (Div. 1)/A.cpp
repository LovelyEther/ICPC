#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int inv(int x) {
	return (n - 1) ^ x;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		if (!k) {
			for (int i = 0; i < n / 2; i ++) printf("%d %d\n", i, inv(i));
		}
		else if (k < n - 1) {
			printf("%d %d\n", k, n - 1);
			printf("%d %d\n", 0, inv(k));
			for (int i = 1; i < n / 2; i ++) if (i != k && i != inv(k)) printf("%d %d\n", i, inv(i));
		}
		else {
			if (n <= 4) puts("-1");
			else {
				printf("%d %d\n", n - 2, n - 1);
				printf("%d %d\n", 1, 3);
				printf("%d %d\n", 0, inv(3));
				for (int i = 2; i < n / 2; i ++) if (i != 3 && i != inv(3)) printf("%d %d\n", i, inv(i));
			}
		}
	}
	return 0;
}
