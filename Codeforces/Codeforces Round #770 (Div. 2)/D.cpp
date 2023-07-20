#include <bits/stdc++.h>
using namespace std;

int query(int i, int j, int k) {
	printf("? %d %d %d\n", i, j, k);
	fflush(stdout);
	int rlt;
	scanf("%d", &rlt);
	return rlt;
}

void answer(int i, int j) {
	printf("! %d %d\n", i, j);
	fflush(stdout);
}

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int mx = -1;
		int id = -1;
		bool change = false;
		for (int i = 3; i <= n; i ++) {
			int val = query(1, 2, i);
			if (mx != -1 && val != mx) change = true;
			if (mx < val) mx = val, id = i;
		}
		if (!change) {
			bool solved = false;
			for (int i = 4; i <= n && !solved; i ++) {
				int val = query(1, 3, i);
				if (val > mx) {
					answer(3, i);
					solved = true;
				}
			}
			if (!solved) {
				answer(1, 2);
			}
			continue;
		}
		mx = -1;
		int jd = -1;
		change = false;
		for (int i = 2; i <= n; i ++) if (i != id) {
			int val = query(1, id, i);
			if (mx != -1 && val != mx) change = true;
			if (mx < val) mx = val, jd = i;
		}
		if (!change) jd = 1;
		answer(id, jd);
	}
	return 0;
}
