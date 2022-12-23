#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) begin(a), end(a)
#define has(a, b) (a.find(b) != a.end())
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)
#define maxval(t) numeric_limits<t>::max()
#define minval(t) numeric_limits<t>::min()
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define sz(x) (int)(x).size()
#define pvec(v) copy(all(v), ostream_iterator<decltype(v)::value_type>(cout, " "))

#define dbgs(x) #x << " = " << x
#define dbgs2(x, y) dbgs(x) << ", " << dbgs(y)
#define dbgs3(x, y, z) dbgs2(x, y) << ", " << dbgs(z)
#define dbgs4(w, x, y, z) dbgs3(w, x, y) << ", " << dbgs(z)

using ll = long long;
using ld = long double;

vector<int> dxs = { -1, 1, 0, 0 };
vector<int> dys = { 0, 0, -1, 1 };

set<pair<int, int>> poss;
bool ok(int i, int j, int dx, int dy) {
	for (int o = -1; o <= 1; ++o) {
		int ddx = dx == 0 ? o : dx;
		int ddy = dy == 0 ? o : dy;
		if (poss.find(mp(i + ddx, j + ddy)) != poss.end()) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string w;
	vector<string> F;
	while (cin >> w) F.pb(w);
	
	int n = sz(F);
	int m = sz(F[0]);

	fora(i, n) fora(j, m) if (F[i][j] == '#') poss.emplace(i, j);

	ll ans = 0;
	fora(_, 1000000) {
		map<pair<int, int>, pair<int, int>> to;
		map<pair<int, int>, pair<int, int>> from;

		bool any = false;

		forc(x, poss) {
			int i = x.first;
			int j = x.second;
			bool mov = false;
			for (int di = -1; di <= 1; di++)
			for (int dj = -1; dj <= 1; dj++) {
				if (di == 0 && dj == 0) continue;
				if (poss.find(mp(i + di, j + dj)) != poss.end()) mov = true;
			}
			if (!mov) continue;	
			any = true;
			fora(d, 4) {
				int dx = dxs[(_ + d) % 4];
				int dy = dys[(_ + d) % 4];

				int ii = i + dx, jj = j + dy;
				if (!ok(i, j, dx, dy)) continue;
				auto p = mp(i, j);
				auto q = mp(ii, jj);
				if (from.find(q) != from.end()) {
					to.erase(from[q]);
					break;
				}
				from[q] = p;
				to[p] = q;
				break;
			}
		}
		if (!any){ ans = _; break; }
		set<pair<int, int>> np;
		forc(x, poss) {
			int i = x.first;
			int j = x.second;
			auto p = mp(i, j);
			if (to.find(p) != to.end()) {
				auto q = to[p];
				np.insert(q);
			} else np.insert(x);
		}
		poss = np;
	}
	cout << ans+1 <<endl;
}
