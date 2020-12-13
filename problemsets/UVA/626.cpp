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
		vvi a(N+1);
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
			cin >> g[i][j];
			if (g[i][j]) a[i].pb(j);
		}
		int ret = 0;
		for (int u = 1; u <= N; u++)
			for (int i=0, v; i<sz(a[u]) && (v=a[u][i]); i++)
				for (int j=0, w; j<sz(a[v]) && (w=a[v][j]); j++) if (g[w][u])
					if ((v-u)*(w-v) > 0)
						cout << u << " " << v << " " << w << endl, ret++;
		cout << "total:" << ret << endl << endl;
	} 

	return 0;
}