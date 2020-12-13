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
	return (c>='a' && c<='z') ? c : ' ';
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	string s; getline(cin, s);
	for (int tt = 1; tt <= TT; tt++) {
		set<string> S;
		vs I;
		while (getline(cin, s) && s != "END") {
			transform(all(s), s.begin(), filter);
			istringstream is(s);
			string u;
			while (is >> u) I.pb(u), S.insert(u);
		} 
		map<string, int> M;
		int q = 0, p = 0,
			k = 0, K = sz(S),
			ret = sz(I)+1, mp, mq;	
		while (q < sz(I)) {
			if (++M[I[q++]] == 1) k++;
			while (k == K && p <= q) {
				if (q-p < ret) ret = q-p, mp = p, mq = q-1;
				if (--M[I[p++]] == 0) k--;
			}
		}
		cout << "Document " << tt << ": " << mp+1 << " " << mq+1 << endl;
	}

	return 0;
}