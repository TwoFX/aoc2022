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

map<int, set<int>> up, dow, lef, rig;
int n, m;

int norm(int x, int m) {
	return ((x % (m - 2)) + (m - 2)) % (m - 2);
}

bool can(int i, int j, int minute) {
	if (i == 0 && j == 1) return true;
	if (i == n - 1 && j == m - 2) return true;
	if (i <= 0 || i >= n - 1 || j <= 0 || j >= m - 1) {
		return false;
	}
	--i;
	--j;
	if (has(up[j], norm(i + minute, n))) return false;
	if (has(dow[j], norm(i - minute, n))) return false;
	if (has(lef[i], norm(j + minute, m))) return false;
	if (has(rig[i], norm(j - minute, m))) return false;
	return true;
}

int solve(int si, int sj, int st, int ti, int tj) {
	deque<tuple<int, int, int>> waiting;
	set<tuple<int, int, int>> seen;
	waiting.eb(si, sj, st);
	while (!waiting.empty()) {
		tuple<int, int, int> cur = waiting.front();
		waiting.pop_front();

		int i = get<0>(cur);
		int j = get<1>(cur);
		int t = get<2>(cur);

		for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy) {
			if ((dx != 0) && (dy != 0)) continue;
			int ii = i + dx, jj = j + dy, tt = t + 1;
			if (can(ii, jj, tt)) {
				tuple<int, int, int> ne = { ii, jj, tt };
				if (ii == ti && jj == tj) {
					return tt;
				}
				if (!has(seen, ne)) {
					seen.insert(ne);
					waiting.pb(ne);
				}
			}
		}
	}
	return 100000000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> f;
	string w;
	while (cin >> w) {
		f.pb(w);
	}

	n = sz(f), m = sz(f[0]);
	fora(i, n) fora(j, m) {
		char c = f[i][j];
		if (c == '^') {
			up[j - 1].insert(i - 1);
		} else if (c == 'v') {
			dow[j - 1].insert(i - 1);
		} else if (c == '<') {
			lef[i - 1].insert(j - 1);
		} else if (c == '>') {
			rig[i - 1].insert(j - 1);
		}
	}

	int a1 = solve(0, 1, 0, n - 1, m - 2);
	int a2 = solve(n - 1, m - 2, a1, 0, 1);
	int a3 = solve(0, 1, a2, n - 1, m - 2);
	cout << a3 << endl;

}
