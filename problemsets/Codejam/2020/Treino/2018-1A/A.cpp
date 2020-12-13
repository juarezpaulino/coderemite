/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iomanip>

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
  int R, C, H, V; re(R,C,H,V);
  vs a(R); re(a);
  int s = 0;
  for (int i=0;i<R;i++)
    for (int j=0;j<C;j++)
      if (a[i][j]=='@')
        s++;
  if (s%((H+1)*(V+1))!=0) { ps("IMPOSSIBLE"); return; }
  if (!s) { ps("POSSIBLE"); return; }
  
  vi rows(R), cols(C);
  for (int i=0;i<R;i++)
    for (int j=0;j<C;j++)
      rows[i]+=a[i][j]=='@';
  for (int i=0;i<C;i++)
    for (int j=0;j<R;j++)
      cols[i]+=a[j][i]=='@';
  
  bool ok = 1;
  // Check rows
  int r = 0, y = 0, ty = s/(H+1);
  int u = 0;
  vpi U;
  for (int i=0;i<R;i++) {
    y += rows[i];
    if (y >= ty) {
      ok &= y==ty;
      r++; y = 0;
      U.eb(mp(u,i+1));
      u = i+1;
    }
  }
  ok &= r==H+1;
  
  // Check columns
  int c = 0, x = 0, tx = s/(V+1);
  int l = 0;
  vpi L;
  for (int j=0;j<C;j++) {
    x += cols[j];
    if (x >= tx) {
      ok &= x==tx;
      c++; x = 0;
      L.eb(mp(l,j+1));
      l = j+1;
    }
  }
  ok &= c==V+1;

  // Check cell
  for (auto &u:U) for (auto &v:L) {
    int c = 0;
    for (int i=u.fi;i<u.se;i++)
      for (int j=v.fi;j<v.se;j++)
        c += a[i][j]=='@';
    ok &= c==s/((H+1)*(V+1));
  } 
  ps(ok?"POSSIBLE":"IMPOSSIBLE");
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