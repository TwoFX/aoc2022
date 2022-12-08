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

	vector<vector<char>> st(10);

	string s;
	cin >> s;

	int jj = 0;
	while (s != "QQQQ"){
		for (int i = sz(s) - 1; i >= 0; --i) {
			st[jj].pb(s[i]);
		}

		cin >> s;
		++jj;
	}

	int amt, from, to;
	while (cin >> amt >> from >> to) {
		--from;
		--to;
		fora(_, amt) {
			st[to].pb(st[from][sz(st[from]) - amt + _]);
		}
		fora(_, amt) {
			st[from].pop_back();
		}
	}
	string ans;
	fora(i, 10) {
		if (sz(st[i]) > 0) {
			ans += st[i].back();
		}
	}
	cout << ans << endl;
}
