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

map<string, int> ids;
vector<int> pres;
vector<vector<int>> adj;
int id(const string &x) {
	if (ids.find(x) != ids.end()) {
		return ids[x];
	}
	int ne = sz(ids);
	adj.eb();
	pres.pb(0);
	ids[x] = ne;
	return ne;
}

map<int, int> tocomp;
map<int, int> fromcomp;

int np(int mask) {
	int ans = 0;
	forc(e, tocomp) {
		int i = e.first;
		int j = e.second;

		if (((mask >> j) & 1) != 0) {
			ans += pres[i];
		}
	}
	return ans;
}

constexpr int inf = -10000;

vector<pair<int, int>> possne(int j) {
	vector<pair<int, int>> ans;
		// Option 1: Do nothing
		ans.eb(j, 0);

		// Option 2: Go somewhere
		forc(ne, adj[j]) {
			ans.eb(ne, 0);
		}

		// Option 3: Open a valve
		if (pres[j] != 0) {
			int newm = (1 << (tocomp[j]));
			ans.eb(j, newm);
		}
		return ans;
}

// time that has passed, current pos, which counting vales are open -> pressure
int dp[2][60][60][1 << 15];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string na;
	cin >> na;
	while (na != "end") {
		int i = id(na);
		cin >> pres[i];

		string q;
		cin >> q;
		while (q != "next") {
			int j = id(q);
			adj[i].pb(j);
			cin >> q;
		}
		cin >> na;
	}

	int n = sz(ids);

	fora(i, n) {
		if (pres[i] == 0) continue;
		int j = sz(tocomp);
		tocomp[i] = j;
		fromcomp[j] = i;
	}

	vector<vector<pair<int, int>>> br(n);
	fora(i, n) {
		br[i] = possne(i);
	}

	vector<int> pnp(1 << 15);
	fora(i, 1 << 15) pnp[i] = np(i);

	cout << "Precomputations completed" << endl;

	fora(j, n) fora(l, n) fora(k, 1 << 15) {
		dp[0][j][l][k] = inf;
		dp[1][j][l][k] = inf;
	}
	dp[0][id("AA")][id("AA")][0] = 0;
	fora(ii, 26) {
		int i = ii % 2;
		fora(j, n) fora(l, j + 1) fora(k, 1 << 15) {
		if (dp[i][j][l][k] == inf) continue;
		int qq = dp[i][j][l][k] + pnp[k];
		forc(u, br[j]) forc(v, br[l]) {
			int a = min(u.first, v.first);
			int b = max(u.first, v.first);
			imax(dp[(i + 1) % 2][b][a][k | u.second | v.second], qq);
		}
	}}

	int ans = 0;
	fora(j, n) fora(l, n) fora(k, 1 << 15) {
		imax(ans, dp[0][j][l][k]);
	}
	cout << ans << endl;

}
