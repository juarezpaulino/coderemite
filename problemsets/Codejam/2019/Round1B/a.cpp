/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MAX = 505050;

struct Bit {
	int n;
  vi t, f;
	Bit(int _n) : n(_n+1) { t = vi(n,0); f = vi(n,0); }
	Bit(vi a) : n(sz(a)+1) {
		for (int i = 0; i < n; i++) f[i]=t[i]=0;
		for (int i = 0; i < n-1; i++) set(i,a[i]);
	}

	void add(int p, int x) { for (f[p++] += x; p < n; p += p&-p) t[p]+=x; }
	void set(int p, int x) { add(p,x-f[p]); }
	int get(int p) {
		int ret = 0;
		for (++p; p; p &= p-1) ret += t[p];
		return ret;
	}
	int get(int l, int r) { return get(r)-get(l-1); }

	int find(int s) {
		bool c;
		for (int l = -1, r = n-1, m; r-l>1; (c)?r=m:l=m)
			m = (l+r)/2, c = (get(m)>=s);
	}
	void scale(int x) { for (int i = 0; i < n; i++) t[i]*=x; }
};



void solve() {
  int P, Q; cin >> P >> Q;
  Bit N(Q+10), S(Q+10), E(Q+10), W(Q+10);
  vi XS, YS;
  XS.eb(0); YS.eb(0);
  while (P--) {
    int x, y; string d;
    cin >> x >> y >> d;
    if (d == "N") N.add(y+1,1), XS.eb(x), YS.eb(y+1);
    if (d == "S") S.add(Q-(y-1),1), XS.eb(x), YS.eb(y-1);
    if (d == "E") E.add(x+1,1), XS.eb(x+1), YS.eb(y);
    if (d == "W") W.add(Q-(x-1),1), XS.eb(x-1), YS.eb(y);
  }
  sort(all(XS)); sort(all(YS));
  int maxi = INT_MIN, x, y, d;
  for (auto &u: XS) {
    if ((d = E.get(u)+W.get(Q-u)) > maxi) x = u, maxi = d;
  }
  maxi = INT_MIN;
  for (auto &u: YS) {
    if ((d = N.get(u)+S.get(Q-u)) > maxi) y = u, maxi = d;
  }
  cout << x << " " << y << endl;
}


int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}