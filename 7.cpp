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

struct info {
	string name;
	ll size;
};

map<vector<string>, vector<info>> files;
map<vector<string>, vector<string>> subdirs;
vector<ll> szs;

ll dfs(vector<string> current) {
	ll self = 0;
	forc(subdir, subdirs[current]) {
		vector<string> down = current;
		down.pb(subdir);
		ll inner = dfs(down);
		self += inner;
	}
	forc(file, files[current]) {
		self += file.size;
	}
	szs.pb(self);
	return self;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	vector<string> current;
	string s;
	while (cin >> s) {
		if (s == "$") {
			string cmd;
			cin >> cmd;
			if (cmd == "cd") {
				string dir;
				cin >> dir;
				if (dir == "..") {
					current.pop_back();
				} else {
					current.pb(dir);
				}
			}
		} else if (s == "dir") {
			string name;
			cin >> name;
			subdirs[current].pb(name);
		} else {
			// file
			ll size = atoll(s.c_str());
			string name;
			cin >> name;
			files[current].pb(info { name, size });
		}
	}

	ll spc = 70000000;

	ll ro = dfs({ "/" });
	ll have = spc - ro;
	ll need = 30000000;
	ll want = need - have;
	sort(all(szs));
	forc(q, szs) {
		if (q >= want) {
			cout << q << endl;
			return 0;
		}
	}
}
