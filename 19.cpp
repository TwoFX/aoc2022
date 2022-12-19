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

struct bp {
	ll id, oreore, clayore, obsore, obsclay, geoore, geoobs;
};

struct state {
	ll min = 0;
	ll rob[4] = { 0, 0, 0, 0 };
	ll res[4] = { 0, 0, 0, 0 };
	bool can[4] = { true, true, true, true };
	ll wr[4] = { 0, 0, 0, 0 };

	bool operator<(const state &other) const {
		return tie(rob[0], rob[1], rob[2], rob[3], res[0], res[1], res[2], res[3]) <
			tie(other.rob[0], other.rob[1], other.rob[2], other.rob[3], other.res[0],
					other.res[1], other.res[2], other.res[3]);
	}
};

void printstate(const state &s, int minute) {
	if (minute == 16 && s.res[0] == 4 && s.res[1] == 21 && s.res[2] == 1) {

	cout << "Minute : " << minute << endl;
	cout << "Robots: " << s.rob[0] << " " << s.rob[1] << " " << s.rob[2]
			<< " " << s.rob[3] << " " << endl;;
	cout << "Resources: " << s.res[0] << " " << s.res[1] << " " << s.res[2]
			<< " " << s.res[3] << " " << endl;;
	cout << endl;
	}
}

constexpr ll minutes = 32;

vector<state> buildrob(const vector<ll> &cost, int id, const vector<state> &states) {
	vector<state> result;
	forc(s, states) {
		state none = s;
		ll canbuild = 100000;
		fora(i, 4) if (cost[i] > 0) {
			imin(canbuild, s.res[i] / cost[i]);
		}
		//if (!s.can[id]) canbuild = 0;
		fora(i, 4) if (s.wr[i] != 0) canbuild = 0;
		imin(canbuild, 1ll);
		for (int amt = 1; amt <= canbuild; ++amt) {
			state t = s;
			fora(i, 4) {
				t.res[i] -= amt * cost[i];
			}
			t.wr[id] += amt;
			result.pb(t);
		}
		if (canbuild >= 1) {
			none.can[id] = false;
		}
		result.pb(none);
	}
	return result;
}

ll bestsofar = 0;

map<pair<ll, state>, ll> seen;

ll dfs(const bp &b, const state &s, int minute) {
	if (minute == minutes + 1) {
		if (s.res[3] > bestsofar) {
			bestsofar = s.res[3];
			cout << "BSF: " << bestsofar << endl;
		}
		return s.res[3];
	}

	ll remaining = minutes - minute + 1;
	ll bestposs = s.res[3] + remaining * s.rob[3] + (remaining * (remaining - 1)) / 2;
	if (bestposs <= bestsofar) {
		return 0;
	}

	if (seen.find(mp(minute, s)) != seen.end()) {
		return seen[mp(minute, s)];
	}

	vector<state> states0 = { s };
	vector<state> states1 = buildrob({ b.oreore, 0, 0, 0 }, 0, states0);
	vector<state> states2 = buildrob({ b.clayore, 0, 0, 0 }, 1, states1);
	vector<state> states3 = buildrob({ b.obsore, b.obsclay, 0, 0 }, 2, states2);
	vector<state> states = buildrob({ b.geoore, 0, b.geoobs, 0 }, 3, states3);

	// Collect ores & finish robots
	for (state &t : states) {
		fora(i, 4) {
			t.res[i] += t.rob[i];
		}
		bool anyr = false;
		fora(i, 4) {
			t.rob[i] += t.wr[i];
			anyr |= t.wr[i] > 0;
			t.wr[i] = 0;
		}
		if (anyr) fora(i, 4) t.can[i] = true;
	}

	ll ans = 0;
	// Recur
	forc(t, states) {
		imax(ans, dfs(b, t, minute + 1));
	}
	seen[mp(minute, s)] = ans;
	return ans;
}

ll solve(const bp &b) {
	seen.clear();
	bestsofar = 0;
	state initial;
	initial.rob[0] = 1;
	return dfs(b, initial, 1);
}

// Wrong; 1483

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bp> bps;

	ll n1, n2, n3, n4, n5, n6, n7;
	while (cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7) {
		bps.pb(bp { n1, n2, n3, n4, n5, n6, n7 });
		if (sz(bps) == 3) break;
	}

	ll ans = 1;
	forc(b, bps) {
		ll a = solve(b);
		cout << dbgs2(b.id, a) << endl;;
		ans *= a;
	}
	cout << ans << endl;
}
