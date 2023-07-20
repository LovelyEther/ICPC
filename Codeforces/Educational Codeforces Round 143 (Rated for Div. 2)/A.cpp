#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m;
char A[N], B[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %s %s", &n, &m, A, B);
		strrev(B);
		strcat(A, B);
		int cnt = 0, len = strlen(A);
		for (int i = 0; i < len - 1; i ++) if (A[i] == A[i+1]) cnt ++;
		puts(cnt <= 1 ? "YES" : "NO");
	}
	return 0;
}
