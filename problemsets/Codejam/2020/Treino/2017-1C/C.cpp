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
  int n, k; re(n,k);
  double u; re(u);
  vd p(n); re(p);
  sort(all(p));
  double ret = 0.;
  for (int i = 0; i < n; i++) {
    double curU = u;
    vd curP = p;
    for (int j = i; j < n; j++) {
      double t = j==n-1 ? 1. : curP[j+1];
      double used = min(curU, (t-curP[j])*(j-i+1));
      curU -= used;
      for (int j1=i;j1<=j;j1++) curP[j1] += used / (j-i+1);
    }
    if (i) curP[i-1] = min(1., curP[i-1]+curU);

    vvd dp(n+1,vd(n+1));
    dp[0][0] = 1.;
    for (int j=0;j<n;j++) for (int l=0;l<n;l++) {
      dp[j+1][l]  +=  dp[j][l]  * (1.-curP[j]);
      dp[j+1][l+1]+=  dp[j][l]  * curP[j];
    }

    double s = 0.;
    for (int j=k;j<=n;j++) s+=dp[n][j];
    if (s > ret) ret = s;
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