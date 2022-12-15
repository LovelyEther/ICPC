#include <bits/stdc++.h>
using namespace std;

int t;
char A[7], B[7];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%s %s", A, B);
		for (int i = 0; i < 5; i ++) putchar(A[i] == B[i] ? 'G' : 'B'); putchar('\n');
	}
	return 0;
}
