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

const int MAX = 505;

struct S {
	int maxi, mini;
	S(int a = 0, int b = 1<<30) : maxi(a), mini(b) {}
	S& operator+=(const S &B) {
		maxi = max(maxi,B.maxi);
		mini = min(mini,B.mini);
		return *this;
	}
	S operator+(const S &B) { return S(*this)+=B; }
};

struct SegmentTree {
	int m, n;
	static S t[MAX<<1][MAX<<1];
	SegmentTree(int m, int n) : m(m), n(n) {
		for (int i = m; i < m<<1; i++)
			for (int j = n; j < n<<1; j++) t[i][j] = S();
		build();
	}
	SegmentTree(vvi &a) : m(sz(a)), n(sz(a[0])) {
		for (int i = m; i < m<<1; i++)
			for (int j = n; j < n<<1; j++) t[i][j] = S(a[i-m][j-n],a[i-m][j-n]);
		build();
	}
	
	void build() {
		// Build at y leaves of x segtrees.
		for (int i = m; i < m<<1; i++)
			for (int j = n-1; j > 0; j--)
				t[i][j] = t[i][j<<1] + t[i][j<<1|1];
		// Build at y parents for each x segtree.
		for (int i = m-1; i > 0; i--)
			for (int j = 2*n-1; j > 0; j--)
				t[i][j] = t[i<<1][j] + t[i<<1|1][j];
	}
	
	void update(int y, int x, S v) {
		t[y+m][x+n] = v;
		
		for (int i = y+m, j = (x+n)>>1; j > 0; j >>= 1)
			t[i][j] = t[i][j<<1] + t[i][j<<1|1];
			
		for (int i = (y+m)>>1; i > 0; i >>= 1)
				for (int j = x+n; j > 0; j >>= 1)
					t[i][j] = t[i<<1][j] + t[i<<1|1][j];		
	}
	S subquery(int p, int l, int r) {
  	S ret;
  	// not closed[l..r) - d+=n
  	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    	if (l&1) ret += t[p][l++];
    	if (r&1) ret += t[p][--r];
  	}
 	 	return ret;
	}	
	S query(int u, int d, int l, int r) {
  	S ret;
  	// not closed[u..d) - d+=m
  	for (u += m, d += m+1; u < d; u >>= 1, d >>= 1) {
    	if (u&1) ret += subquery(u++,l,r);
    	if (d&1) ret += subquery(--d,l,r);
  	}
 		return ret;
	}
};

S SegmentTree::t[MAX<<1][MAX<<1];


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N; cin >> N;
	vvi A(N+1,vi(N+1));
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> A[i][j];
	SegmentTree T(A);
	int Q; cin >> Q;
	while (Q--) {
		char c;
		int y1, x1, y2, x2;
		cin >> c;
		if (c == 'q') {
			cin >> x1 >> y1 >> x2 >> y2;
			S ret = T.query(x1,x2,y1,y2);
			cout << ret.maxi << " " << ret.mini << endl;
		}
		else {
			cin >> x1 >> y1 >> x2;
			T.update(x1,y1,S(x2,x2));
		}
	}

	return 0;
}