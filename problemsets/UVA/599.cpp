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
typedef tuple<string,set<string>,int> tc;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

char filter(char c) {
	return (c>='A'&&c<='Z')?c:' ';
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
	string s; getline(cin,s);
	while (TT--) {
		vi out;
		set<int> OUT;
		UnionFind G(26);
		while (getline(cin,s)) {
			if (s[0]=='*') break;
			transform(all(s), s.begin(), filter);
			istringstream is(s);
			char a, b;
			while (is >> a >> b) if (!G.join(a-'A', b-'A')) out.pb(a-'A');
		}
		for (auto u: out) OUT.insert(G.find(u));
		int ret = 0, t = 0; char a;
		getline(cin,s);
		transform(all(s), s.begin(), filter);
		istringstream is(s);
		while (is >> a) {
			a = a-'A';
			if (OUT.count(G.find(a))) continue;
			if (G.up[a]==-1) ret++;
			else if (a == G.find(a)) t++; 
		}
		cout << "There are " << t << " tree(s) and " << ret << " acorn(s)." << endl;
	}

	return 0;
}