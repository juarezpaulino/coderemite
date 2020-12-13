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

struct UnionFind {
	vi up;
	UnionFind(int N) { up = vi(N,-1); }
	int find(int u) { return up[u]<0 ? u : up[u] = find(up[u]); }
	bool same(int u, int v) { return find(u)==find(v); }
	bool join(int u, int v) {
	    if ((u=find(u)) == (v=find(v))) return false;
	    if (up[v] < up[u]) swap(u,v);
	    up[u] += up[v]; up[v] = u;
	    return true;
	}
};


int main() {

//	setbuf(stdout, NULL);
	ios::sync_with_stdio(0);
//	cin.tie(0);

	int TT; cin >> TT;
	while (TT--) {
		int P, T; cin >> P >> T;
		vector<set<int>> H(P);
		string s;
		getline(cin,s);
		while (getline(cin,s) && !s.empty()) {
			istringstream is(s);
			int p,t; is >> p >> t; p--; t--;
			H[p].insert(t);
		}
		UnionFind U(P);
		int ret = 0;
		for (int i = 0; i < P; i++) for (int j = i+1; j < P; j++) if (H[i]==H[j]) U.join(i,j);
		for (int i = 0; i < P; i++) if (U.up[i] < 0) ret++;
		cout << ret << endl;
		if (TT) cout << endl;
	}

	return 0;
}