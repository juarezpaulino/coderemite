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
#define mt make_tuple
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
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;

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

void solve() {
  int r, c; re(r,c);
  vi s(r*c); re(s);
  vvi g(r*c,vi(4,-1));
  int dy[] = { -1, 0, 1, 0 };
  int dx[] = { 0, -1, 0, 1 };

  for (int i=0;i<r*c;i++) {
    int y = i/c, x = i%c;
    for (int j=0;j<4;j++) {
      int ny=y+dy[j], nx=x+dx[j];
      if (ny>=0 && ny<r && nx>=0 && nx<c)
        g[i][j]=ny*c+nx;
    }
  }

  auto eliminate = [&](int u) {
    int v = 0, t = 0;
    for (int i=0;i<4;i++) if (g[u][i]!=-1) {
      v++;
      t+=s[g[u][i]];
    }
    return v*s[u] < t;
  };

  set<int> out;
  queue<int> q;
  ll sum = 0;
  for (int i=0;i<r*c;i++) {
    sum += s[i];
    if (eliminate(i)) {
      q.push(i);
      out.insert(i);
    }
  }

  function<int(int,int)> search = [&](int u, int k) {
    int v = g[u][k];
    if (out.count(v))
      v = search(v,k);
    return g[u][k] = v;
  };

  ll ret = sum;
  while (!q.empty()) {
    set<int> possible;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      sum -= s[u];
      for (int i=0;i<4;i++) {
        int v = search(u,i);
        if (v != -1) {
          g[v][(i+2)%4] = search(u,(i+2)%4);
          possible.insert(v);
        }
      }
    } 
    for (auto u:possible) if (eliminate(u)) {
      out.insert(u);
      q.push(u);
    }
    ret += sum;
  }
  ps(ret);
}


main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}