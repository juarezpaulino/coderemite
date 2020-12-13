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

struct SegmentTree {
	int n;
	static int t[MAX<<1];
	SegmentTree(int n) : n(n) {
		for (int i = n; i < n<<1; i++) t[i] = 0;
		build();
	}
	SegmentTree(vi &a) : n(sz(a)) {
		for (int i = n; i < n<<1; i++) t[i] = a[i-n];
		build();
	}
	
	void build() {
		for (int i = n - 1; i > 0; --i)
			t[i] = t[i<<1] + t[i<<1|1];
	}
	void update(int p, int x) {
		for (t[p += n] = x; p > 1; p >>= 1)
			t[p>>1] = t[p] + t[p^1];
	}
	int query(int l, int r) {
  	int ret = 0;
  	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    	if (l&1) ret += t[l++];
    	if (r&1) ret += t[--r];
  	}
 	 return ret;
	}
};

int SegmentTree::t[MAX<<1];


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, tt = 1;
	while (cin >> N && N != 0) {
		if (tt != 1) cout << endl;
		vi a(N+1);
		for (int i = 1; i <= N; i++) cin >> a[i];
		SegmentTree T(a);
		string s; int x1, y1;
		cout << "Case " << tt++ << ":" << endl;
		while (cin >> s && s != "END") {
			cin >> x1 >> y1;
			if (s == "M") cout << T.query(x1,y1) << endl;
			else T.update(x1,y1);
		}
	}

	return 0;
}