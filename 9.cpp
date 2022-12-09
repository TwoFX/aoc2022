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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	set<pair<ll, ll>> tps;

	char d;
	ll a;
	vector<int> x(10), y(10);
	while (cin >> d >> a) {
		fora(_, a) {
		if (d == 'L') {
			x[0] -=1 ;
		} else if (d == 'R') x[0] += 1;
		else if (d == 'U') y[0] += 1;
		else if (d == 'D') y[0] -= 1;

		fora(i, 9) {
			if (abs(x[i] - x[i + 1]) >= 2 || abs(y[i] - y[i + 1]) >= 2) {
				if (x[i] > x[i + 1]) ++x[i + 1];
				if (x[i] < x[i + 1]) --x[i + 1];
				if (y[i] > y[i + 1]) ++y[i + 1];
				if (y[i] < y[i + 1]) --y[i + 1];
			}
		}
		tps.emplace(x[9], y[9]);
		}
	}
	cout << sz(tps) << endl;
}
