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

int prio(char c) {
	if (c <= 'z' && c >= 'a') {
		return c - 'a' + 1;
	}
	if (c <= 'Z' && c >= 'A') {
		return c - 'A' + 27;
	}
	return -1;
}

vector<bool> g(const string &s) {
	vector<bool> ans(256);
	forc(c, s) ans[c] = true;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> a;
	string x;
	while (cin >> x) a.pb(x);
	int n = sz(a);

	ll ans = 0;
	fora(i, n / 3) {
		vector<bool> q = g(a[3 * i]), r = g(a[3 * i + 1]), s = g(a[3 * i + 2]);
		fora(i, 256) if (q[i] && r[i] && s[i]) {
			ans += prio((char)i);
		}
	}
	cout << ans << endl;
}
