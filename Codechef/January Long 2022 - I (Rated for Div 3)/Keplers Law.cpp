#include <bits/stdc++.h>
using namespace std;

int t, T1, T2, R1, R2;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &T1, &T2, &R1, &R2);
		puts(T1 * T1 * R2 * R2 * R2 == T2 * T2 * R1 * R1 * R1 ? "Yes" : "No");
	}
	return 0;
}
