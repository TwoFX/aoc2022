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

int id(int i, int j) {
	return i * m + j;
}

int gi(int id) {
	return id / m;
}

int gj(int id) {
	return id % m;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> f;
	string ff;
	while (cin >> ff) f.pb(ff);
	n  = sz(f);
	m = sz(f[0]);

	vector<ll> dist(n * m, 1000000);

	int src = -1;
	int dest = -1;
	fora(i, n) fora(j, m) {
		if (f[i][j] == 'S') {
			src = id(i, j);
			f[i][j] = 'a';
		}
		if (f[i][j] == 'E') {
			dest = id(i, j);
			f[i][j] = 'z';
		}
	}

	deque<int> q;
	q.pb(dest);
	dist[dest] = 0;

	while (!q.empty()) {
		int cur = q.front();
		 q.pop_front();
		int i = gi(cur), j = gj(cur);
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				if ((dx == 0) == (dy == 0)) continue;
				int ii = i + dx, jj = j + dy;
				if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
				if (f[ii][jj] - f[i][j] < -1) continue;
				int to = id(ii, jj);
				if (dist[to] > dist[cur] + 1) {
					dist[to] = dist[cur] + 1;
					q.pb(to);
				}
			}
		}
	}
	ll ans = 10000000;
	fora(i, n) fora(j, m) if (f[i][j] == 'a') imin(ans, dist[id(i, j)]);
	cout << ans << endl;
}
