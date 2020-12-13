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
typedef vector<vpii> vvi;
typedef vector<string> vs;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int M, N;
	while (cin >> M >> N) {
		vvi ret(N+1, vpii());
		for (int i = 1; i <= M; i++) {
			int r, x; cin >> r;
			vi idx;
			for (int j = 0; j < r; j++) cin >> x, idx.pb(x);
			for (int j = 0; j < r; j++) cin >> x, ret[idx[j]].pb(mp(i,x));
		}
		cout << N << " " << M << endl;
		for (int i = 1; i <= N; i++) {
			cout << sz(ret[i]);
			for (int j = 0; j < sz(ret[i]); j++) cout << " " << ret[i][j].fi;
			cout << endl;
			for (int j = 0; j < sz(ret[i]); j++) cout << (j?" ":"\0") << ret[i][j].se;
			cout << endl;
		}
	}

	return 0;
}