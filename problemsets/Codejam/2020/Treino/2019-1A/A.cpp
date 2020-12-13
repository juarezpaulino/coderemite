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
#define ms(x,b) memset(x,b,sizeof(x))
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;

namespace input {
  template<class T1, class T2> void re(pair<T1,T2>& p);
  template<class T> void re(vector<T>& a);
  template<class T> void re(T& x) { cin >> x; }
  void re(double& x) { string t; re(t); x = stod(t); }
  template<class A, class... As> void re(A& head, As&... tail) {
    re(head); re(tail...);
  }
  template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.fi,p.se); }
  template<class T> void re(vector<T>& a) { for (int i=0; i<sz(a); i++) re(a[i]); }
}
using namespace input;
namespace output {
  template<class T1, class T2> void pr(const pair<T1,T2>& x);
  template<class T> void pr(const vector<T>& x);
  template<class T> void pr(const set<T>& x);
  template<class T1, class T2> void pr(const map<T1,T2>& x);
  template<class T> void pr(const T& x) { cout << fixed << setprecision(10) << x; }
  template<class A, class... As> void pr(const A& head, const As&... tail) {
    pr(head); pr(tail...);
  }
  template<class T1, class T2> void pr(const pair<T1,T2>& x) {
    pr("{",x.fi,", ",x.se,"}");
  }
  template<class T> void prc(const T& x) {
    pr("{");
    bool fi = 1; for (auto &a: x) pr(!fi?", ":"",a), fi = 0;
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

vi computed[25][25];
mt19937 rng(17);

void precompute() {
  for (int r=2;r<21;r++) for (int c=2;c<21;c++) {
    vvi adj(r*c);
    for (int y=0;y<r;y++) for (int x=0;x<c;x++) {
      for (int i=0;i<r;i++) for (int j=0;j<c;j++) {
        if (y!=i && x!=j && y+x!=i+j && y-x!=i-j)
          adj[y*c+x].eb(i*c+j);
      }
    }
    for (auto &u:adj) shuffle(all(u),rng);
    // Backtrack to solution.
    vi cur, ret, vis(r*c);
    function<void(int,int)> backtrack = [&](int k, int u) {
      if (!ret.empty()) return;
      cur.eb(u); vis[u]=1;
      if (k == r*c) ret = cur;
      for (auto &v:adj[u]) if (!vis[v]) backtrack(k+1,v);
      cur.pop_back(); vis[u]=0; 
    };
    for (int i=0;i<r*c;i++) backtrack(1,i);
    computed[r][c]=ret;
//    ps(r,c,"OK - size:",sz(ret));
  }
}

void solve() {  
  int r, c; re(r,c);
  if (computed[r][c].empty()) ps("IMPOSSIBLE");
  else {
    ps("POSSIBLE");
    for (auto &u:computed[r][c]) ps(u/c+1,u%c+1); 
  }
}

main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);

  precompute();  

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}