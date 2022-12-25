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

ll g(string &s) {
		ll num = 0;
		ll q = 1;
		reverse(all(s));
		forc(c, s) {
			ll val;
			if (c == '-') {
				val = -1;
			} else if (c == '=') {
				val = -2;
			} else val = c - '0';
			num += q * val;
			q *= 5;
		}
		return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	ll ans = 0;
	string s;
	while(cin >> s) {
		ans += g(s);
	}
	cout << ans << endl;
	string res;
	while (ans > 0) {
		ll rem = ans % 5;
		if (rem == 4) {
			res += '-';
			ans += 1;
		} else if (rem == 3) {
			res += '=';
			ans += 2;
		} else {
			res += (char)('0' + rem);
			ans -= rem;
		}
		ans /= 5;
	}
	reverse(all(res));
	cout << res << endl;
	cout << g(res) << endl;
}
