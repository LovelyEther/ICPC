#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1ll << 62;

int t;
ll L, R;

bool live(ll x, int p) {
	return x & (1ll << p);
}

pair <int, ll> solve(ll x, int p, ll L, ll R) {
	if (L == 0 && R == inf) {
		return make_pair(__builtin_popcountll(x), x);
	}
	pair <int, ll> rlt = make_pair(66, inf);
	if (x > R || (x >> p + 1) < (L >> p + 1)) return rlt;
	if (x > R) return rlt;
	if (p == -1) return make_pair(__builtin_popcountll(x), x);
	if (live(L, p) && live(R, p)) {
		return min(solve(x, p - 1, L, inf), solve(x ^ (1ll << p), p - 1, L, R));
	}
	else if (live(L, p) && !live(R, p)) {
		return min(solve(x, p - 1, L, R), solve(x ^ (1ll << p), p - 1, L, R));
	}
	else if (!live(L, p) && live(R, p)) {
		return min(solve(x, p - 1, L, inf), solve(x ^ (1ll << p), p - 1, 0, R));
	}
	else {
		return min(solve(x, p - 1, L, R), solve(x ^ (1ll << p), p - 1, 0, R));
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t --) {
		cin >> L >> R;
		cout << solve(0, 60, L, R).second << endl;
	}
	return 0;
}
