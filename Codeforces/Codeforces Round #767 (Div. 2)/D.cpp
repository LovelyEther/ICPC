#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[11], ss[11];
map <string, int> mp;

bool pal(char* s) {
	int len = strlen(s);
	return s[0] == s[len-1];
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		mp.clear();
		bool valid = false;
		for (int i = 1; i <= n; i ++) {
			scanf("%s", s);
			strcpy(ss, s);
			if (pal(s)) valid = true;
			strrev(s);
			if (mp.count(s)) valid = true;
			if (strlen(s) == 2) {
				for (int c = 'a'; c <= 'z'; c ++) {
					s[2] = c; s[3] = 0;
					if (mp.count(s)) valid = true;
				}
			}
			else if (strlen(s) == 3) {
				s[2] = 0;
				if (mp.count(s)) valid = true;
			}
			mp[ss] = 1;
		}
		puts(valid ? "YES" : "NO");
	}
	return 0;
}
