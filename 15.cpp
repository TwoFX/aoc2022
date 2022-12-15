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

struct sens {
	ll x1, y1, x2, y2;
};

struct event {
	ll pos;
	// 0 = start, 1 = end
	ll type;

	bool operator<(const event &other) {
		return tie(pos, type) < tie(other.pos, other.type);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x1, y1, x2, y2;
	//ll want = 2000000;
	ll ma = 4000000;
	ll mult = 4000000;
	vector<sens> ss;
	set<pair<ll, ll>> no;

	while (cin >> x1 >> y1 >> x2 >> y2) {
		ss.pb(sens { x1, y1, x2, y2});
		no.emplace(x2, y2);
	}
	
	fora(row, ma + 1) {
		vector<event> ev;
		forc(s, ss) {
			ll mand = abs(s.x1 - s.x2) + abs(s.y1 - s.y2);
			ll rem = mand - abs(s.y1 - row);
			if (rem >= 0) {
				ev.pb(event { s.x1 - rem, 0 });
				ev.pb(event { s.x1 + rem + 1, 1 });
			}
			if (row == s.y2) {
				ev.pb(event { s.x2, 0 });
				ev.pb(event { s.x2 + 1, 1 });
			}
		}
		sort(all(ev));

		int active = 0;
		forc(e, ev) {
			if (e.type == 0) {
				++active;
			} else if (e.type == 1) {
				--active;
			}
			if (active == 0 && e.pos >= 0 && e.pos <= ma) {
				cout << dbgs2(row, e.pos) << endl;;
				ll ans = mult * e.pos + row;
				cout << ans << endl;
				return 0;
			}
		}
	}
}
