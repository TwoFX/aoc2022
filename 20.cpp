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

	vector<pair<ll, ll>> a;
	ll x;
	int i = 0;
	while (cin >> x) {
		a.eb(i, x);
		i++;
	}

	ll key = 811589153;
	
	int n = sz(a);
	fora(i, n) {
		a[i].second = (a[i].second * key);
	}


	fora(_, 10) fora(i, n) {
		int j = -1;
		fora(k, n) if (a[k].first == i) j = k;
		int amt = a[j].second % (n - 1);
		if (amt < 0 && j + amt <= 0) {
			amt = n + amt - 1;
		}
		if (amt > 0 && j + amt >= n) {
			amt = amt - n + 1;
		}
		fora(_, abs(amt)) {
			int partner = amt > 0 ? j + 1 : j - 1;
			partner = ((partner % n) + n) % n;
			swap(a[j], a[partner]);
			j = partner;
		}
	}

	int j0 = -1;
	fora(i, n) {
		if (a[i].second == 0) j0 = i;
	}
	ll ans = a[(j0 + 1000) % n].second + a[(j0 + 2000) % n].second + a[(j0 + 3000) % n].second;
	cout << ans << endl;
}
