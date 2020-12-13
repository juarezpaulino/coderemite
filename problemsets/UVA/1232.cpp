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


#define L(u) ((u)<<1)
#define R(u) (((u)<<1)+1)
struct SegmentTree {
	vi mini, maxi, lazy;
	int N;
	SegmentTree(int N) : N(N) { mini = maxi = lazy = vi(N<<2,0); }
	int query(int u, int l, int r, int i, int j, int v) {
		if (i > r || j < l) return -1;
		
		if (lazy[u]) {
			mini[u] = maxi[u] = lazy[u];
			if (L(u) < sz(lazy)) lazy[L(u)] = lazy[u];
			if (R(u) < sz(lazy)) lazy[R(u)] = lazy[u];
			lazy[u] = 0;
		}	
		
		if (l >= i && r <= j) {
			if (v < mini[u]) return 0;
			if (v >= maxi[u]) {
				maxi[u] = mini[u] = v;
				if (L(u) < sz(lazy)) lazy[L(u)] = v;
				if (R(u) < sz(lazy)) lazy[R(u)] = v;
				return r-l+1;
			}
		}
		
		int m = (l+r)>>1;
		int vl = query(L(u), l, m, i, j, v);
		int vr = query(R(u), m+1, r, i, j, v);
		if (vl != -1) maxi[u] = max(maxi[u], maxi[L(u)]), mini[u] = min(mini[u], mini[L(u)]);
		if (vr != -1) maxi[u] = max(maxi[u], maxi[R(u)]), mini[u] = min(mini[u], mini[R(u)]);
		return  vl==-1 ? vr :
	   			vr==-1 ? vl :
	   			vl+vr;		
	}
	int query(int i, int j, int v) { return query(1, 0, N-1, i, j, v); }
};

int lo, hi;

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		int N; cin >> N;
		int ret = 0;
		lo = 1<<30, hi = 0;
		vvi I;
		while (N--) {
			int l, r, h; cin >> l >> r >> h;
			I.pb({l,r-1,h});
			lo = min(lo, l);
			hi = max(hi, r-1);
		}
		transform(all(I), I.begin(), [](vi A) { return vi({A[0]-lo, A[1]-lo, A[2]}); });
		hi -= lo;
		SegmentTree T(hi+1);
		for (auto u: I) { ret += T.query(u[0], u[1], u[2]); }
		cout << ret << endl;
	}

	return 0;
}