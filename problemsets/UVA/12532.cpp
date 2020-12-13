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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


const int MAX = 100020;

struct Bit {
	int n;
	// t[] - number of -1, z[] - number of zeroes.
	static int f[MAX], t[MAX], z[MAX];
	Bit(int _n) : n(_n+1) { for (int i = 0; i < n; i++) f[i]=1,t[i]=z[i]=0; }
	Bit(vi a) : n(sz(a)+1) {
		for (int i = 0; i < n; i++) f[i]=1,t[i]=z[i]=0;
		for (int i = 0; i < n-1; i++) set(i,a[i]);
	}

	void set(int p, int x) {
		if (x==f[p]) return;
		int u = f[p];
		for (f[p++]=x; p < n; p += p&-p) {
			if (!u) z[p]--;
			if (u<0) t[p]--;
			if (!x) z[p]++;
			if (x<0) t[p]++;
		}
	}
	pii get(int p) {
		pii ret = mp(0,0);
		for (++p; p; p &= p-1) ret = mp(ret.fi+t[p], ret.se+z[p]);
		return ret;
	}
	pii get(int l, int r) {
		pii L = get(l-1);
		pii R = get(r);
		return mp(R.fi-L.fi, R.se-L.se);
	}

};

int Bit::t[MAX], Bit::f[MAX], Bit::z[MAX];


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, K, tt = 1;
	while (cin >> N >> K) {
		if (tt != 1) cout << endl;
		vi a(N+1);
		a[0] = 1;
		for (int i = 1; i <= N; i++) cin >> a[i], a[i] /= (a[i]?abs(a[i]):1);
		Bit T(a);
		char s; int u, v;
		while (K--) {
			cin >> s >> u >> v;
			if (s == 'P') { pii ret = T.get(u,v); cout << (ret.se?"0":ret.fi%2?"-":"+"); }
			else T.set(u,v/(v?abs(v):1));
		}
		tt++;
	}
	cout << endl;

	return 0;
}