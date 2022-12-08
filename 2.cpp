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

char todraw(char fi, char se) {
	if (fi == 'A') {
		return 'X';
	} else if (fi == 'B') {
		return 'Y';
	} else {
		return 'Z';
	}
}
char tolose(char fi, char se) {
	if (fi == 'A') {
		return 'Z';
	} else if (fi == 'B') {
		return 'X';
	} else {
		return 'Y';
	}
}

char towin(char fi, char se) {
	if (fi == 'A') {
		return 'Y';
	} else if (fi == 'B') {
		return 'Z';
	} else {
		return 'X';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans = 0;
	char fi;
	while (cin >> fi) {
		char se;
		cin >> se;

		char t;
		if (se == 'X') {
			t = tolose(fi, se);
		} else if (se == 'Y') {
			t = todraw(fi, se);
		} else {
			t = towin(fi, se);
		}

		ans += t - 'X' + 1;
		if (fi - 'A' == t - 'X') ans += 3;
		if (se == 'Z') ans += 6;
	}
	cout << ans << endl;
}
