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

vector<int> dxs = { 0, 1, 0, -1 };
vector<int> dys = { 1, 0, -1, 0 };
vector<char> sym = { '>', 'v', '<', '^'};

int n;
bool debug;

struct pos {
	int x, y, dir;
};

// sides: 0 = top, 1 = right, 2 = bottom, 3 = left
pos g(int r, int c, int side, int p, bool negate) {
	if (negate) p = n - p - 1;
	if (side == 0) {
		return pos { n * r, n * c + p, 1 };
	} else if (side == 1) {
		return pos { n * r + p, n * c + n - 1, 2 };
	} else if (side == 2) {
		return pos { n * r + n - 1, n * c + p, 3 };
	} else {
		return pos { n * r + p, n * c, 0 };
	}
}

pos leave(pos from) {
	int r = from.x / n;
	int c = from.y / n;
	int xo = from.x - n * r;
	int yo = from.y - n * c;
	int dir = from.dir;
	int p = (dir == 0 || dir == 2) ? xo : yo;

	if (r == 0 && c == 2) {
		// Face 1
		if (dir == 0) {
			return g(2, 1, 1, p, true);
		} else if (dir == 1) {
			return g(1, 1, 1, p, false);
		} else if (dir == 2) {
			return g(0, 1, 1, p, false);
		} else if (dir == 3) {
			return g(3, 0, 2, p, false);
		}
	} else if (r == 0 && c == 1) {
		// Face 2
		if (dir == 0) {
			return g(0, 2, 3, p, false);
		} else if (dir == 1) {
			return g(1, 1, 0, p, false);
		} else if (dir == 2) {
			return g(2, 0, 3, p, true);
		} else if (dir == 3) {
			return g(3, 0, 3, p, false);
		}
	} else if (r == 1 && c == 1) {
		// Face 3
		if (dir == 0) {
			return g(0, 2, 2, p, false);
		} else if (dir == 1) {
			return g(2, 1, 0, p, false);
		} else if (dir == 2) {
			return g(2, 0, 0, p, false);
		} else if (dir == 3) {
			return g(0, 1, 2, p, false);
		}
// sides: 0 = top, 1 = right, 2 = bottom, 3 = left
	} else if (r == 2 && c == 1) {
		// Face 4
		if (dir == 0) {
			return g(0, 2, 1, p, true);
		} else if (dir == 1) {
			return g(3, 0, 1, p, false);
		} else if (dir == 2) {
			return g(2, 0, 1, p, false);
		} else if (dir == 3) {
			return g(1, 1, 2, p, false);
		}
	} else if (r == 2 && c == 0) {
		// Face 5
		if (dir == 0) {
			return g(2, 1, 3, p, false);
		} else if (dir == 1) {
			return g(3, 0, 0, p, false);
		} else if (dir == 2) {
			return g(0, 1, 3, p, true);
		} else if (dir == 3) {
			return g(1, 1, 3, p, false);
		}
	} else if (r == 3 && c == 0) {
		// Face 6
		if (dir == 0) {
			return g(2, 1, 2, p, false);
		} else if (dir == 1) {
			return g(0, 2, 0, p, false);
		} else if (dir == 2) {
			return g(0, 1, 0, p, false);
		} else if (dir == 3) {
			return g(2, 0, 2, p, false);
		}
	}
	cout << "Unknown!!!!!!" << endl;
	return g(0, 0, 0, 0, false);
}
// sides: 0 = top, 1 = right, 2 = bottom, 3 = left
//pos g(int r, int c, int side, int p, bool negate) {
//

bool isin(int x, int y, int r, int c) {
	return x >= n *  r && x < n * (r + 1) && y >= n * c && y < n * (c + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string p;
	cin >> p;
	string w;
	vector<string> f;
	while (cin >> w) f.pb(w);

	int longest = 0;
	forc(q, f) imax(longest, sz(q));
	for (string &q : f) {
		while (sz(q) < longest) q += '!';
	}

	n = sz(f) == 12 ? 4 : 50;
	debug = n == 4;
	//int n = sz(f);

	//vector<vector<vector<char>>> F(n + 2, vector<vector<char>>(n + 2, vector<char>(n + 2, ' ')));


	int curx = 0;
	int cury = 0;
	int dir = 0;

	fora(i, sz(f[0])) if (f[0][i] != '!') {
		cury = i;
		break;
	}

	int r = curx / n;
	int c = cury / n;
	
	stringstream coms(p);
	string com;
	while(getline(coms, com, ',')) {
		if (com == "R") dir = (dir + 1) % 4;
		else if (com == "L") dir = (dir + 3) % 4;
		else {
			ll amt = atoll(com.c_str());
				f[curx][cury] = sym[dir];
			int prevx = curx, prevy = cury, prevdir = dir;
			fora(_, amt) {
				curx += dxs[dir];
				cury += dys[dir];

				if (!isin(curx, cury, r, c)) {
			forc(q, f) cout << q << endl;
			cout << endl << endl;
					cout << "Leaving " << dbgs4(curx, cury, r, c) << endl;
					pos ne = leave(pos { prevx, prevy, dir });
					curx = ne.x;
					cury = ne.y;
					dir = ne.dir;
					r = curx  / n;
					c = cury / n;
					cout << "Landed " << dbgs4(curx, cury, r, c) << endl;
				}

				if (f[curx][cury] == '#') {
					curx = prevx;
					cury = prevy;
					dir = prevdir;
					r = curx  / n;
					c = cury / n;
					break;
				} else {
					prevx = curx;
					prevy = cury;
					prevdir = dir;
				}

				f[curx][cury] = sym[dir];
			}

		}
	}


	ll row = curx + 1;
	ll col = cury + 1;
	cerr << 1000 * row + 4 *col + dir << endl;
}
