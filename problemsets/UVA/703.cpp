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


int g[101][101];

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N;
	while (cin >> N) {
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> g[i][j];
		vvi ret;
		for (int u = 1; u <= N; u++) 
			for (int v = 1; v <= N; v++) if (u != v)
				for (int w = 1; w <= N; w++) if (v != w && w != u)
					if ((v-u)*(w-v) > 0 && (g[u][v]&g[v][w]&g[w][u])) ret.pb({u,v,w});
					else if (u<v && v<w && !(g[u][v]|g[v][u]|g[v][w]|g[w][v]|g[w][u]|g[u][w])) ret.pb({u,v,w});
		cout << sz(ret) << endl;
		for (int i = 0; i < sz(ret); i++) cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << endl;
	} 

	return 0;
}