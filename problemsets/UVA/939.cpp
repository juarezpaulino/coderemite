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

map<string, int> G;
map<string, vs> P;

void dfs(string u) {
	int c = 0;
	for (auto v: P[u]) {
		if (G[v]==-1) dfs(v);
		c += G[v];
	}
	G[u] = (c==4 || c==2) ? 1 : (c < 4) ? 0 : 4;
}

int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	map<string, int> R = {{"dominant",4},{"recessive",1},{"non-existent",0}};
	int N; cin >> N;
	while (N--) {
		string a, b; cin >> a >> b;
		if (R.count(b)) G[a] = R[b];
		else P[b].pb(a), G[b] = -1;
	}
	for (auto u: G) if (u.se==-1) dfs(u.fi);
	for (auto u: G) cout << u.fi << " " << (u.se==0?"non-existent":u.se==1?"recessive":"dominant") << endl;

	return 0;
}