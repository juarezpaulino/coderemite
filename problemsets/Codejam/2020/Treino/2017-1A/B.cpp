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
#define mt make_tuple
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
  int n, p; re(n,p);
  vi r(n); re(r);
  vvi q(n,vi(p)); re(q);
  vector<tuple<int,int,int>> I;
  for (int i=0;i<n;i++) {
    for (int j=0;j<p;j++) {
      int left = (10*q[i][j] + 11*r[i] - 1) / (11*r[i]);
      int right = 10*q[i][j] / (9*r[i]);
      if (left<=right) I.eb(mt(right,left,i));
    }
  }
  sort(all(I));
  int kit = 0;
  vi c(n), skip(n);
  set<int> taken;
  int k = 0;;
  for (int i=0;i<sz(I);i++) {
    int l, r, t;
    tie(r,l,t) = I[i];
    while (k<i && get<0>(I[k]) < l) {
      int l1, r1, t1;
      tie(l1,r1,t1) = I[k];
      if (skip[t1]) skip[t1]--;
      else if (--c[t1]==0) taken.erase(t1);
      k++;
    }
    ++c[t];
    taken.insert(t);
//    ps("In loop: ", sz(taken), l, r, t);
    if (sz(taken)==n) {
      kit++;
      for (int i=0;i<n;i++) {
        if (--c[i]==0)
          taken.erase(i);
        skip[i]++;
      }
    }
//    ps("Count: ",c);
  }
  ps(kit);
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