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

	int TT; cin >> TT;
	while (TT--) {
		int G; cin >> G;
		vvi g; int x, c, e; char z;
		for (int i = 0; i < G; i++) cin >> x >> c >> z >> e, g.pb({x,c,e});
		vs ret;
		for (int n = 0; n < 10000; n++) {
			int u[10] = {0}, v[10];
			for (int i = 0, x = n; i < 4; i++, x/=10) u[x%10]++;
			bool ok = 1;
			for (int k=0; ok && k < G; k++) {
				c = e = 0;
				copy(u,u+10,v);
				int w = 0;
				for (int i=0,x=n,y=g[k][0]; i < 4; i++,x/=10,y/=10)
					if (x%10==y%10) c++, v[x%10]--, w |= (1<<i);
				for (int i=0,x=n,y=g[k][0]; i < 4; i++,x/=10,y/=10) if (!(w&(1<<i)))
					if (v[y%10]) e++, v[y%10]--;
				ok &= (c==g[k][1]) && (e==g[k][2]);
			}
			if (ok) { string s = to_string(n); ret.pb(string(4-sz(s),'0')+s); }
			if (sz(ret) > 1) break;
		}
		if (sz(ret)==0) cout << "impossible" << endl;
		else if (sz(ret)>1) cout << "indeterminate" << endl;
		else cout << ret[0] << endl; 
	}
	
	return 0;
}