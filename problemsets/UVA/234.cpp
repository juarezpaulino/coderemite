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

	int p, P[8], v[8], retp[8], tt = 1;
	int a; pii A[8];
	while (cin >> p && p) {
		for (int i = 0; i < p; i++) cin >> P[i];
		cin >> a; for (int i = 0; i < a; i++) cin >> A[i].fi >> A[i].se;
		vi ret(6,1<<30);
		int o[8] = {0,1,2,3,4,5,6,7};
		do {
			vi t(6,0);
			v[0]=P[o[0]]; for (int i = 1; i < p; i++) v[i]=v[i-1]+P[o[i]];
			for (int k = 0; k < a; k++) {
				int m = A[k].se;
				for (int i = 0; i < p; i++) m = min(m,abs(A[k].se-v[i]));
				t[A[k].fi] += m;
			}
			if (t < ret) {
				ret = t;
				for (int i = 0; i < p; i++) retp[i] = P[o[i]];
			}
		} while (next_permutation(o,o+p));
		cout << "Data set " << tt++ << endl;
		cout << "  Order:";
		for (int i = 0; i < p; i++) cout << " " << retp[i];
		cout << endl;
		cout << "  Error: " << accumulate(all(ret),0) << endl;
	}
	
	return 0;
}