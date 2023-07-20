#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int c;
	scanf("%d", &c);
	return c;
}

void answer(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int t;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		int r = 0;
		for (int i = 1; i <= 30; i ++) {
			int s = (1 << i - 1) - r;
			int x = query(s, s + (1 << i));
			if (x == (1 << i)) r += 1 << i - 1;
		}
		answer(r);
	}
	return 0;
}
