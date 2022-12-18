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

bool occ[30][30][30];
bool seen[30][30][30];

ll ans = 0;

set<tuple<int, int, int, int, int, int>> arr;


void dfs(int x, int y, int z, int adx, int ady, int adz) {
	if (x < 0 || x >= 30 || y < 0 || y >= 30 || z < 0 || z >= 30) return;
	if (occ[x][y][z]) {
		arr.emplace(x, y, z, adx, ady, adz);
		return;
	}
	if (seen[x][y][z]) {
		return;
	}

	seen[x][y][z] = true;

	for (int dx = -1; dx <= 1; ++dx)
	for (int dy = -1; dy <= 1; ++dy)
	for (int dz = -1; dz <= 1; ++dz) {
		int nu = (dx != 0) + (dy != 0) + (dz != 0);
		if (nu != 1) continue;
		int xx = x + dx, yy = y + dy, zz = z + dz;
		dfs(xx, yy, zz, dx, dy, dz);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	ll x, y, z;
	while (cin >> x >> y >> z) {
		occ[x + 3][y + 3][z + 3] = true;
	}

	dfs(0, 0, 0, 0, 0, 0);
	cout << sz(arr) << endl;

}
