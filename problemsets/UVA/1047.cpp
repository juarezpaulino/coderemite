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

inline unsigned rev(unsigned x) {
x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
return x;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(0);

	int tt = 1;
	int n, m;
	while (cin >> n >> m && n+m) {
		vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
		int k; cin >> k;
		vpii L(k);
		for (auto &l: L) {
			int t, x; cin >> t;
			l.fi = 0;
			while (t--) cin >> x, l.fi |= 1<<(x-1);
			cin >> l.se;
		}
		int ret = 0, retc = 0;
		for (int k = 1; k < (1<<n); k++) if (on(k)==m) {
			int c = 0, x;
			for (int i = 0; i < n; i++) if (k&(1<<i)) c += a[i];
			for (auto l: L) if (x = (l.fi&k)) c -= (on(x)-1)*l.se;
			if (c > retc) ret = k, retc = c;
		}
		cout << "Case Number  " << tt++ << endl;
		cout << "Number of Customers: " << retc << endl;
		cout << "Locations recommended:";
		for (int i = 0; i < n; i++) if (ret&(1<<i)) cout << " " << i+1;
		cout << endl << endl;
	}

	
	return 0;
}
