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
typedef vector<vi> vvi;

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

typedef vector<vi> vvi;

void solve() {
  int n; re(n);
  vvi s, t = vvi(n,vi(n,1));
  for (int i=0;i<n;i++) {
    string a; re(a);
    vi x;
    for (auto u:a) x.eb(u=='#');
    s.eb(x);
  }
  int ret = 1E8;
  for (int k = 0; k < 4; k++) {
    vvi u = s;
    int c = __builtin_popcount(k);
    if (k&1) for (int i=0;i<n;i++) u[i][i]^=1;
    if (k&2) for (int i=0;i<n-1;i++) u[i][i+1]^=1;
    for (int l=0;l<2*n-1;l++) {
      if (!u[l/2][l/2+l%2]) {
        c++;
        for (int i=0;i<=l;i++) {
          int y=i, x=l-i;
          if (y>=0 && y<n && x>=0 && x<n) u[y][x]^=1;
        }
      }
    }
    for (int i=1;i<n;i++) if (!u[i][0]) {
      c++;
      for (int j=0;j<n;j++) {
        int y=i+j, x=j;
        if (y>=n) break;
        u[y][x]^=1;
      }
    }
    for (int j=2;j<n;j++) if (!u[0][j]) {
      c++;
      for (int i=0;i<n;i++) {
        int y=i, x=i+j;
        if (x>=n) break;
        u[y][x]^=1;
      }
    }
    if (u==t) ret = min(ret, c);
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