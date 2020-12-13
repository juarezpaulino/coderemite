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
#define pb push_back
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


void solve() {
  int n; re(n);
  vector<bool> unbounded(n+1);
	vvi g(n+1), comp, adj(n+1);
	vl val(n+1);

  FOR(i,1,n+1) {
    int u, v; re(u,v);
    if (u==i || v==i) unbounded[i] = 1;
    g[i].eb(u); adj[u].eb(i);
    g[i].eb(v); adj[v].eb(i);
  }
  FOR(i,1,n+1) re(val[i]);

  vi c(n+1), vis(n+1,0), l(n+1), s;
	vector<bool> b(n+1);
  int nord = 0;
  function<void(int)> dfs = [&](int u) {
	  vis[u] = l[u] = ++nord;
	  s.pb(u); b[u] = 1;
	  for (int v: g[u]) {
		  if (!vis[v]) dfs(v);
		  if (b[v]) l[u] = min(l[u], l[v]);
	  }
	  if (vis[u]!=l[u]) return;
	 	vi r;
	 	for (int v = s.back(); b[u]; v = s.back())
	  	r.pb(v), c[v] = sz(comp), b[v] = 0, s.pop_back();
	  comp.pb(r);
	};
  for (int u = 1; u <= n; u++) if (!vis[u]) dfs(u);
  
  vi vis2(n+1,0), hasflow(n+1,0);
  FOR(i,1,n+1) hasflow[i] = val[i]!=0;
  vi prof(n+1), ord(n+1);
  nord = 0;
  function<void(int)> dfs2 = [&](int u) {
	  vis2[u] = 1;
	  for (int v: adj[u]) if (!vis2[v]) dfs2(v);
	  ord[nord++] = u;
	};
	dfs2(1);
	
	bool ok = 1;
  FOR(i,0,nord) {
    int u = ord[i];
    if (hasflow[u] && (unbounded[u] || sz(comp[c[u]])!=1)) ok = 0;
    FORE(v,g[u])
      val[v]=(val[v]+val[u])%MOD,
      hasflow[v] |= hasflow[u];
  }
  if (!ok) pr("UNBOUNDED\n");
  else pr(val[1],'\n');
}


int main() {
  //setbuf(stdout, NULL);
  //cin.tie(0);
  ios::sync_with_stdio(0);
  int t; re(t);
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}