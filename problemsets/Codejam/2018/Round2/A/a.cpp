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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
//	ios::sync_with_stdio(0);

	int TT; cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
		cout << "Case #" << tt << ": ";
		int C; cin >> C;
		vi B = vi(C);
		int t = 0;
		for (int i = 0; i < C; i++) cin >> B[i], t += B[i];

		if (t != C || !B[0] || !B[C-1]) { cout << "IMPOSSIBLE" << endl; continue; }

		vs ret(1, string(C,'.'));
		int used = 0;
		for (int k = 0; k < C; k++) {
			if (!B[k]) continue;
			int l = used;
			for (int p = 0; p < B[k]; p++, l++) {
				int i = 0, j = l;
				while (j != k) {
					if (i == sz(ret)) ret.pb(string(C,'.'));
					ret[i][j] = (j < k) ? (j++, '\\') : (j--, '/');
					i++;
				}
				if (i == sz(ret)) ret.pb(string(C,'.'));
			}
			used += B[k];
		}

		cout << sz(ret) << endl;
		for (int i = 0; i < sz(ret); i++) cout << ret[i] << endl;
	}

    return 0;
}