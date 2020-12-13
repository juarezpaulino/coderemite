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

void solve() {
  int N;
  vi C(6);
  re(N,C);
  string color = "ROYGBV";
  bool ok = 1;
  int np = 0;
  set<int> dual;
  // check for duality problem
  for (int i=0;i<6;i+=2) np += C[i]!=0; 
  for (int u=1;u<6;u+=2) {
    int v = (u+3)%6;
    int x = C[u], y = C[v];
    ok &= y==x;
    if (x) dual.insert(u);
  }
  if (np==1 && sz(dual)==1) {
    if (!ok) { ps("IMPOSSIBLE"); return; }
    int k = 0;
    int u = *begin(dual), v = (u+3)%6;
    for (int i=0;i<N;i++) {
      pr(k?color[u]:color[v]);
      k = 1-k;
    }
    ps(); return;
  }

  // check for secondary
  vi C2 = C;
  ok = 1;
  for (int u=1;u<6;u+=2) {
    int v = (u+3)%6;
    int x = C[u], y = C[v];
    if (!x) continue;
    if (y < x+1) ok = 0;
    C2[v]-=x;
  } 
  if (!ok) { ps("IMPOSSIBLE"); return; }

  vi ord = {0,2,4};
  sort(all(ord),[&](int u, int v){return C2[u]>C2[v];});
  string sol(C2[0]+C2[2]+C2[4],' ');
  int m = sz(sol);
  int k = 0;
  for (int z=0;z<2;z++) {
    for (int i=z;i<m;i+=2) {
      sol[i] = color[ord[k]];
      if (--C2[ord[k]]==0) k++;
    }
  }
  for (int i=0;i<m;i++) if (sol[i]==sol[(i+1)%m]) ok = 0;
  if (!ok) { ps("IMPOSSIBLE"); return; }

  auto concat = [](string u, int n) {
    string ret = "";
    while (n--) ret += u;
    return ret;
  };
  for (int k=0;k<6;k+=2) {
    if (!C[(k+3)%6]) continue;
    for (int i=0;i<sz(sol);i++) if (sol[i]==color[k]) {
      sol = sol.insert(i,concat(string(1,color[k])+color[(k+3)%6],C[(k+3)%6]));
      break;
    }
  }
  ps(sol);
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