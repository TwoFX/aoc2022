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

int n;
vector<vector<ll>> items(10);
vector<char> op(10);
vector<ll> operand(10);
vector<ll> di(10);
vector<ll> le(10);
vector<ll> ri(10);
vector<ll> cnt(10);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	fora(i, n) {
		ll item;
		cin >> item;
		while (item != -1) {
			items[i].pb(item);
			cin >> item;
		}
		cin >> op[i] >> operand[i] >> di[i] >> le[i] >> ri[i];
	}
	cout << "INput" << endl;

	fora(round, 10000) {
		fora(i, n) {
			forc(it, items[i]) {
				++cnt[i];
				ll ii = it;
				ll opn = operand[i] == -1 ? ii : operand[i];
				if (op[i] == '+') {
					ii += opn;
				} else ii *= opn;
				ii %= 223092870;
				if (ii % di[i] == 0) {
					items[le[i]].pb(ii);
				} else {
					items[ri[i]].pb(ii);
				}
			}
			items[i].clear();
		}
		/*fora(i, n) {
			cout << "Monkey " << i << ": ";
			forc(ii, items[i]) cout << ii << " ";
			cout << endl;
		}*/
	}
	sort(all(cnt));
	forc(c, cnt) cout << c << endl;
	cout << cnt[8] * cnt[9] << endl;
}
