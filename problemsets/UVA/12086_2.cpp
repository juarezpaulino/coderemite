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

const int MAX = 200020;

struct Bit {
	int n;
	static int t[MAX], f[MAX];
	Bit(int _n) : n(_n+1) { for (int i = 0; i < n; i++) t[i]=f[i]=0; }
	Bit(vi a) : n(sz(a)+1) {
		for (int i = 0; i < n; i++) t[i]=f[i]=0;
		for (int i = 0; i < n; i++) set(i,a[i]);
	}

	void add(int p, int x) { for (f[p++] += x; p < n; p += p&-p) t[p]+=x; }
	void set(int p, int x) { add(p,x-f[p]); }
	int get(int p) {
		int ret = 0;
		for (++p; p; p &= p-1) ret += t[p];
		return ret;
	}
	int get(int l, int r) { return l?get(r)-get(l-1):get(r); }

	int find(int s) {
		bool c;
		for (int l = -1, r = n-1, m; r-l>1; (c)?r=m:l=m)
			m = (l+r)/2, c = get(m)>=s;
	}
	void scale(int x) { for (int i = 0; i < n; i++) t[i]*=x; }
};

int Bit::t[MAX], Bit::f[MAX];


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, tt = 1;
	while (cin >> N && N != 0) {
		if (tt != 1) cout << endl;
		vi a(N+1);
		for (int i = 1; i <= N; i++) cin >> a[i];
		Bit T(a);
		string s; int x1, y1;
		cout << "Case " << tt++ << ":" << endl;
		while (cin >> s && s != "END") {
			cin >> x1 >> y1;
			if (s == "M") cout << T.get(x1,y1) << endl;
			else T.set(x1,y1);
		}
	}

	return 0;
}