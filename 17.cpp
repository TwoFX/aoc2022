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

vector<vector<string>> rocks = {
	{ "####" },
	{ ".#.", "###", ".#." },
	{ "..#", "..#", "###" },
	{ "#", "#", "#", "#" },
	{ "##", "##" } };

vector<int> asi(const vector<string> &rock) {
	int n = sz(rock);
	int m = sz(rock[0]);
	vector<int> ans(n);
	fora(i, n) {
		fora(j, m) {
			if (rock[i][j] == '#') ans[i] |= (1 << (j + 3));
		}
	}
	reverse(all(ans));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string p;
	cin >> p;
	cout << sz(p) << endl;

	vector<vector<int>> ris = vector<vector<int>>(5);
	fora(i, 5) ris[i] = asi(rocks[i]);

	ll high = 0;
	ll lastper = 0;
	ll lasthigh = 0;
	ll lastblast = 0;
//	ll rounds = 1000000000000;
	ll rounds = 1000000000000; // 1523615160352
	//ll rounds = 10000000; // 1523611
	//ll rounds = 123456; // 188116
	//ll rounds = 2022;
	ll per = 1130 + 585;
	ll hper = 1750 + 863;
	ll bper = 6677 + 3414;
	
	bool slow = false;

	vector<int> field(min(10000000ll, 4 * rounds + 20), 1 | (1 << 8));
	field[0] = (1 << 9) - 1;

	ll blast, round, ans;
	if (!slow) {
		rounds -= 216;
		blast = 1250 + bper * (rounds / per);
		round = 216 + per * (rounds / per);
		ans = 325 + hper * (rounds / per);
		rounds += 216;
	} else {
		ans = 0;
		round = 0;
		blast = 0;
	}
	for (; round < rounds; ++round) {
		vector<int> ro = ris[round % 5];
		ll cur = high + 4;
		while (true) {
			// Jet
			bool dir = p[blast % sz(p)] == '<';
			++blast;
			bool poss = true;
			fora(i, sz(ro)) {
				if (dir) {
					poss &= ((ro[i] >> 1) & field[cur + i]) == 0;
				} else {
					poss &= ((ro[i] << 1) & field[cur + i]) == 0;
				}
			}
			if (dir) {
				if (poss) fora(i, sz(ro)) ro[i] >>= 1;
			} else {
				if (poss) fora(i, sz(ro)) ro[i] <<= 1;
			}

			// Fall
			poss = true;
			fora(i, sz(ro)) {
				poss &= (ro[i] & field[cur + i - 1]) == 0;
			}
			if (poss) --cur;
			else break;
		}
		fora(i, sz(ro)) field[cur + i] |= ro[i];
		imax(high, cur + sz(ro) - 1);
		if (field[high] == (((1 << 9) - 1))) {
			cout << dbgs3(round - lastper, high - lasthigh, blast - lastblast) << endl;
			lastper = round;
			lasthigh = high;
			lastblast = blast;
		}
		//high = cur + sz(ro);
		/*fora(i, 20) {
			cout << bitset<9>(field[20 - i - 1]) << endl;
		}
		cout << endl << endl;*/
	}
	cout << ans + high << endl;
}
