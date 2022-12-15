#include <bits/stdc++.h>
using namespace std;

#define N 200200

int C, col[N], tot[N], cnt[N];
vector <int> v[N];

void dfs(int x) {
    col[x] = C;
    tot[C] += cnt[x];
    for (int i = 0; i < v[x].size(); i ++) if (!col[v[x][i]]) dfs(v[x][i]);
}

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        map <string, int> mp;
        int n = 0;
        for (int i = 0; i < words.size(); i ++) {
            if (!mp.count(words[i])) mp[words[i]] = ++ n;
        }
        for (int i = 0; i < words.size(); i ++) {
            int x = mp[words[i]];
            cnt[x] ++;
            for (int j = 0; j < words[i].size(); j ++) {
                string ta = "";
                for (int k = 0; k < words[i].size(); k ++) if (k != j) ta += words[i][j];
                if (!mp.count(ta)) {
					int y = mp[ta];
					v[x].push_back(y);
					v[y].push_back(x);
                }
				ta = words[i];
                for (char c = 'a'; c <= 'z'; c ++) {
                    ta[j] = c;
                    if (!mp.count(ta)) continue;
                    int y = mp[ta];
                    v[x].push_back(y);
                    v[y].push_back(x);
                }
            }
        }
        for (int i = 1; i <= n; i ++) if (!col[i]) C ++, dfs(i);
        int mx = 0;
        for (int i = 1; i <= C; i ++) if (mx < tot[i]) mx = tot[i];
        vector <int> rlt;
        rlt.push_back(C);
        rlt.push_back(mx);
        return rlt;
    }
} A;

int main() {
	freopen("in.txt", "r", stdin);
	vector <string> words;
	words.push_back("a");
	words.push_back("ab");
	words.push_back("abc");
	vector <int> rlt = A.groupStrings(words);
	printf("%d %d\n", rlt[0], rlt[1]);
	return 0;
}
