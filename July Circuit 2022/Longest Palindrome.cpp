#include <bits/stdc++.h>
using namespace std;

#define N 1010

typedef pair < vector <int>, vector <int> > pvivi;

int n, k, f[N][N], prv[N], nxt[N], idx[N];
int del[N], ord[N];
char s[N];
bool pal[N][N];

void prepare() {
	for (int i = 1; i <= n; i ++) pal[i][i] = 1;
	for (int i = 1; i < n; i ++) pal[i][i+1] = (s[i] == s[i+1]);
	for (int d = 3; d <= n; d ++) {
		for (int i = 1; i + d - 1 <= n; i ++) {
			int j = i + d - 1;
			pal[i][j] = (s[i] == s[j] && pal[i+1][j-1]);
		}
	}
	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= n; j ++) {
			f[i][j] = 0;
			if (s[i] == s[j]) f[i][j] = 1 + f[i+1][j-1];
			if (i <= j) f[i][j] = min(f[i][j], (j - i + 1) / 2);
		}
	}
}

int get_cnt() {
	int cnt = 0;
	for (int i = 1; i <= n; i ++) if (del[i-1] && !del[i]) cnt ++;
	return cnt;
}

pvivi solve(int type = 0) {
	memset(del, 0, sizeof del);
	memset(ord, 0, sizeof ord);
	del[0] = del[n+1] = 1;
	vector <int> v, w;
	while (1) {
		int r = k - v.size() - get_cnt() - 1; // 1 for center
		if (type >= 2 && r < k / 4) r = min(r, 3);
		int mx = 0, ii = 0, jj = 0;
		vector <int> js;
		if (type % 2 == 0) {
			for (int j = 1; j <= n; j ++) if (!del[j]) js.push_back(j);
		}
		else {
			for (int j = n; j >= 1; j --) if (!del[j]) js.push_back(j);
		}
		if (type >= 5 && js.size() > 0) {
			random_shuffle(js.begin(), js.end());
		}
		for (int i = 1; i <= n; i ++) if (!del[i]) {
			for (auto j: js) {
				if (!del[i-1] + !del[i+f[i][j]] + !del[j+1] + !del[j-f[i][j]] > r) continue;
				if (type <= 3) {
					if (f[i][j] > mx) mx = f[i][j], ii = i, jj = j;
					else if (f[i][j] == mx) {
						if (!del[i-1] + !del[i+mx] + !del[j+1] + !del[j-mx] < !del[ii-1] + !del[ii+mx] + !del[jj+1] + !del[jj-mx]) {
							ii = i, jj = j;
						}
					}
				}
				else {
					if (f[i][j] * 3 / 2 + del[i-1] + del[i+mx] + del[j+1] + del[j-mx] > 
						f[ii][jj] * 3 / 2 + del[ii-1] + del[ii+mx] + del[jj+1] + del[jj-mx]) {
						ii = i, jj = j;
					}
				}
			}
		}
		mx = f[ii][jj];
		if (!mx) break;
		for (int i = ii; i < ii + mx; i ++) del[i] = 1;
		for (int j = jj; j > jj - mx; j --) del[j] = 1;
		v.push_back(ii + mx - 1);
		v.push_back(jj);
		for (int i = 1; i <= n; i ++) {
			prv[i] = del[i-1] ? i - 1 : prv[i-1];
		}
		for (int j = n; j >= 1; j --) {
			nxt[j] = del[j+1] ? j + 1 : nxt[j+1];
		}
		for (int i = 1; i <= n; i ++) if (!del[i]) {
			for (int j = 1; j <= n; j ++) if (!del[j]) {
				f[i][j] = min(f[i][j], min(nxt[i] - i, j - prv[j]));
			}
		}
	}
	int orded = 0;
	if (v.size() + get_cnt() == k) {
		assert(0);
		for (int i = 0; i < v.size(); i += 2) {
			ord[v[i]] = i / 2 + 1;
			ord[v[i+1]] = v.size() - i / 2;
		}
		orded = v.size();
	}
	else {
		int r = k - v.size() - get_cnt();
		int mx = 0, ii = 0, jj = 0;
		for (int i = 1; i <= n; i ++) if (!del[i]) {
			for (int j = i; j <= n && !del[j]; j ++) if (pal[i][j]) {
				if (!del[i-1] + !del[j+1] > r) continue;
				if (j - i + 1 > mx) mx = j - i + 1, ii = i, jj = j;
			}
		}
		v.push_back(jj);
		for (int i = ii; i <= jj; i ++) del[i] = 1;

		for (int i = 0; i < v.size() - 1; i += 2) {
			ord[v[i]] = i / 2 + 1;
			ord[v[i+1]] = v.size() - i / 2;
		}
		ord[v[v.size()-1]] = v.size() / 2 + 1;
		orded = v.size();
		while (v.size() + get_cnt() < k) {
			for (int i = 1; i <= n; i ++) if (!del[i]) {
				del[i] = 1;
				v.push_back(i);
				break;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (!del[i] && del[i+1]) v.push_back(i);
	}
	sort(v.begin(), v.end());
	//for (int i = 0; i < k; i ++) printf("%d\n", v[i]);
	int mx = 0, ii = 0, jj = -1;
	for (int i = 0; i < k; i ++) if (!ord[v[i]]) {
		for (int j = 0; j < k; j ++) if (!ord[v[j]] && j != i) {
			int sti = i ? v[i-1] + 1 : 1;
			int eni = v[i];
			int stj = j ? v[j-1] + 1 : 1;
			int enj = v[j];
			int tmp = f[sti][enj];
			tmp = min(tmp, eni - sti + 1);
			tmp = min(tmp, enj - stj + 1);
			if (tmp > mx) mx = tmp, ii = i, jj = j;
		}
	}
	if (mx > 0) {
		for (int i = 0; i < k; i ++) if (ord[v[i]]) ord[v[i]] ++;
		ord[v[jj]] = 1;
		ord[v[ii]] = orded + 2;
		orded += 2;
	}
	for (int i = 0; i < k; i ++) {
		if (!ord[v[i]]) ord[v[i]] = ++ orded;
	}
	for (int i = 1; i <= k; i ++) idx[ord[v[i-1]]] = i;
	//for (int i = 1; i <= k; i ++) printf("%d%c", idx[i], i < k ? ' ' : '\n');
	for (int i = 1; i <= k; i ++) w.push_back(idx[i]);
	return make_pair(v, w);
}

vector <int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector <int> p(n + 2);
    int l = 0, r = -1;
    for (int i = 1; i <= n; i ++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i] ++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector <int>(begin(p) + 1, end(p) - 1);
}

vector <int> manacher(string s) {
    string t;
    for (auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector <int>(begin(res) + 1, end(res) - 1);
}

int get_score(pvivi p) {
	string t = "";
	for (int i = 0; i < k; i ++) {
		int j = p.second[i] - 1;
		int st = j ? p.first[j-1] + 1 : 1;
		int en = p.first[j];
		for (int j = st; j <= en; j ++) t += s[j];
	}
	vector <int> rad = manacher(t);
	int rlt = 0;
	for (int i = 0; i < rad.size(); i ++) rlt = max(rlt, rad[i] - 1);
	return rlt;
}

int main() {
	scanf("%d %d %s", &n, &k, s + 1);
	prepare();
	pvivi ans = solve();
	for (int type = 1; type <= 5; type ++) {
		pvivi tmp = solve(type);
		if (get_score(tmp) > get_score(ans)) ans = tmp;
	}
	for (int i = 0; i < k; i ++) printf("%d\n", ans.first[i]);
	for (int i = 0; i < k; i ++) printf("%d%c", ans.second[i], i < k - 1 ? ' ' : '\n');
	return 0;
}
