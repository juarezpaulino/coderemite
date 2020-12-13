/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define on(x) (__builtin_popcount(x))
#define ctz(x) (__builtin_ctz(x))
inline int szb(int a) { int ret = 1; while(a>>=1) ret++; return ret; }

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef tuple<string,set<string>,int> tc;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

char filter(char c) {
	char d = tolower(c);
	return (d>='a' && d<='z') ? c : ' ';
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	int TT; cin >> TT;
	while (TT--) {
		int C; cin >> C;
		vector<tc> M;
		vector<set<string> > ret(C, set<string>());
		while (C--) {
			tc x;
			string c;
			int W, P;
			cin >> get<0>(x) >> W >> get<2>(x);
			while (W--) { string s; cin >> s; get<1>(x).insert(s); }
			M.pb(x);
		}
		string s;
		getline(cin, s);
		while (getline(cin, s) && !s.empty()) {
			transform(all(s), s.begin(), filter);
			istringstream is(s);
			string u;
			while (is >> u) for (int i = 0; i < sz(M); i++)
				if (get<1>(M[i]).count(u)) ret[i].insert(u); 
		}
		bool ok = 0;
		for (int i = 0; i < sz(M); i++) {
			if (sz(ret[i]) >= get<2>(M[i])) {
				if (ok) cout << ",";
				cout << get<0>(M[i]);
				ok = 1;
			}
		}
		if (ok) cout << endl;
		else cout << "SQF Problem." << endl;
	}

	return 0;
}