/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORE(a, x) for (auto& a : x)

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define sz(v) ((int) (v).size())
#define beg(x) begin(x)
#define all(v) beg(v), end(v)
#define sqr(x) ((x)*(x))
#define ms(x,b) memset(x,b,sizeof(x))

const int MOD = 1000000007;
const ll INF = 1E18;
const double EPS = 1E-10;

template<class T> T ckmin(T &a, T b) { return a = min(a, b); }
template<class T> T ckmax(T &a, T b) { return a = max(a, b); }

namespace input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class A, class... As> void re(A& head, As&... tail) { 
        re(head); re(tail...); 
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { FOR(i,0,sz(a)) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
    template<class T> void pr(const T& x) { cout << x; }
    template<class A, class... As> void pr(const A& head, const As&... tail) { 
        pr(head); pr(tail...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prc(const T& x) {
        pr("{");
        bool fi = 1; FORE(a,x) pr(!fi?", ":"",a), fi = 0; 
        pr("}");
    }
    template<class T> void pr(const vector<T>& x) { prc(x); }
    template<class T> void pr(const set<T>& x) { prc(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prc(x); }
    
    void ps() { pr("\n"); } 
    template<class A, class... As> void ps(const A& head, const As&... tail) { 
        pr(head," "); ps(tail...);
    }
}

using namespace output;


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
  setbuf(stdout, NULL);
  //cin.tie(0);
  ios::sync_with_stdio(0);
  int v[] = { 4, 8, 15, 16, 23, 42 };
  map<int,pi> m;
  FOR(i,0,6) FOR(j,i+1,6) m[v[i]*v[j]] = mp(v[i],v[j]);
  auto find_intersection = [](pi &a, pi &b) {
    if (a.f == b.f) return a.f;
    if (a.f == b.s) return a.f;
    return a.s;
  };
  vi ret(6);
  int x;
  pi a, b;
  pr("? 1 2\n"); re(x); a = m[x];
  pr("? 2 3\n"); re(x); b = m[x];
  ret[1] = find_intersection(a,b);
  ret[0] = ret[1]==a.f ? a.s : a.f;
  ret[2] = ret[1]==b.f ? b.s : b.f;
  pr("? 4 5\n"); re(x); a = m[x];
  pr("? 5 6\n"); re(x); b = m[x];
  ret[4] = find_intersection(a,b);
  ret[3] = ret[4]==a.f ? a.s : a.f;
  ret[5] = ret[4]==b.f ? b.s : b.f;
  pr("!"); FORE(u,ret) pr(" ",u); pr("\n");
}
