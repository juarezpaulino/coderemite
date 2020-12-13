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
#define clz(x) (__builtin_clz(x))
#define szb(x) (sizeof(int)*8 - clz(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<double> vd;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, tt = 1;
	while (cin >> N && N!=-1) {
		vd L(N); vi G(N), Y(N), R(N);
		for (int i = 0; i < N; i++) cin >> L[i] >> G[i] >> Y[i] >> R[i];
		int l = -1;
		bool can;
		vpii ret;
		for (int v = 30; v <= 60; v++) {
			double V = v;
			can = 1;
			for (int i = 0; i < N; i++) {
				double t = L[i]*3600./v;
				if (cmp( fmod(t,G[i]+Y[i]+R[i]), G[i]+Y[i]) > 0) { can = 0; break; }
			}
			if (!can && l>0) ret.pb(mp(l,v-1)), l = -1;
			else if (can && l<0) l = v; 
		}
		if (can) ret.pb(mp(l,60));
		cout << "Case " << tt++ << ":";
		if (!sz(ret)) cout << " No acceptable speeds.";
		else for (int i = 0; i < sz(ret); i++) {
			if (i) cout << ",";
			cout << " ";
			if (ret[i].fi == ret[i].se) cout << ret[i].fi;
			else cout << ret[i].fi << "-" << ret[i].se;
		}
		cout << endl;
	}

	return 0;
}