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

int ret;
vi g[3003];
int G[3003][3003], tt;

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	for (tt = 1; tt <= TT; tt++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) g[i].clear();
		while (m--) {
			int u, v; cin >> u >> v;
			if (v < u) swap(u,v);
			g[u].pb(v);
			G[u][v] = G[v][u] = tt;
		}
		ret = 0;
		for (int u = 1; u <= n; u++)
			for (auto v = g[u].begin(); v != g[u].end(); v++)
				for (auto w = v+1; w != g[u].end(); w++)
					if (G[*v][*w]==tt) ret++;
		cout << ret << endl;
	}
	
	return 0;
}