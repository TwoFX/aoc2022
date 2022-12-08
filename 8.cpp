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

int n, m;
vector<vector<int>> f;

ll check(int i, int j) {
	ll ans = 1;
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if ((dx == 0) == (dy == 0)) continue;
			ll q = 1;
			int ii = i + dx, jj = j + dy;
			while (true) {
				if (!(ii >= 0 && ii < n && jj >= 0 && jj < m)) {
					--q;
					break;
				}
				if (ii >= 0 && ii < n && jj >= 0 && jj < m && f[ii][jj] >= f[i][j]) {
					// Last tree
					break;
				}
				++q;
				ii += dx;
				jj += dy;
			}
			ans *= q;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> field;
	string ff;
	while (cin >> ff) field.pb(ff);
	n = sz(field);
	m = sz(field[0]);


	vector<vector<bool>> vis(n, vector<bool>(m));
	f = vector<vector<int>>(n, vector<int>(m));
	fora(i, n) fora(j, m) f[i][j] = field[i][j] - '0';

	ll ans = 0;
	fora(i, n) fora(j, m) imax(ans, check(i, j));

	cout << ans << endl;
}
