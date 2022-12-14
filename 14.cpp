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

bool blocked[1000][200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int lowest = 0;
	int x = -1, y = -1;
	int nx, ny;
	while (cin >> nx >> ny) {
		if (x != -1 && nx != -1) {
			int x1 = min(x, nx);
			int x2 = max(x, nx);
			int y1 = min(y, ny);
			int y2 = max(y, ny);
			imax(lowest, y2);

			for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j) {
				blocked[i][j] = true;
			}
		}
		x = nx;
		y = ny;
	}

	fora(i, 1000) {
		blocked[i][lowest + 2] = true;
	}

	ll ans = 0;
	while (true) {
		int cx = 500, cy = 0;
		while (true) {
			if (!blocked[cx][cy + 1]) {
				++cy;
			} else if (!blocked[cx - 1][cy + 1]) {
				++cy;
				--cx;
			} else if (!blocked[cx + 1][cy + 1]) {
				++cy;
				++cx;
			} else {
				break;
			}
		}
		if (!blocked[500][0]) {
			++ans;
			blocked[cx][cy] = true;
		} else {
			break;
		}
	}
	cout << ans << endl;
}
