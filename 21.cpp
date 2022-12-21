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

bool isn(const string &s) {
	return s[0] >= '0' && s[0] <= '9';
}

string getn(const string &s) {
	return s.substr(0, sz(s) - 1);
}
struct o {
	string l;
	char c;
	string r;
};

struct val {
	ld hum;
	ld con;
};

map<string, val> fin;
map<string, o> oos;

val eval(string m) {
	if (fin.find(m) != fin.end()) {
		cout << dbgs3(m, fin[m].hum, fin[m].con) << endl;
		return fin[m];
	}

	o oo = oos[m];
	val l = eval(oo.l), r = eval(oo.r);
	ld ansh, ansc;
	if (oo.c == '/') {
		ansh = l.hum / r.con;
		ansc = l.con / r.con;
		if (r.hum != 0) {
			cout << "Hmm at " << r.hum << endl;
		}
	} else if (oo.c == '+') {
		ansh = l.hum + r.hum;
		ansc = l.con + r.con;
	} else if (oo.c == '*') {
		if (l.hum != 0 && r.hum != 0) {
			cout << "Hmm at " << r.hum << " and " << l.hum << endl;
		}
		ansh = l.hum * r.con + l.con * r.hum;
		ansc = l.con * r.con;
	} else if (oo.c == '=') {
		ansh = 1;
		ansc = 1;
		ld ans = (r.con - l.con) / l.hum;
		cout << setprecision(15) << ans << endl;
	} else {
		ansh = l.hum - r.hum;
		ansc = l.con - r.con;
	}
	fin[m] = val { ansh, ansc };
	cout << dbgs3(m, ansh, ansc) << endl;
	return fin[m];
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	while (cin >> s) {
		string nam = getn(s);
		string op;
		cin >> op;
		if (isn(op)) {
			ll v = atoll(op.c_str());
			if (nam == "humn") {
				fin[nam] = val { 1, 0 };
			} else {
				fin[nam] = val { 0, v };
			}
		} else {
			char c; string r;
			cin >> c >> r;
			oos[nam] = o { op, c , r};
		}

	}
	oos["root"].c = '=';
	eval("root");
}
