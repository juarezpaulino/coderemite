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
#define sqr(x) ((x)*(x))

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void solve() {
  int n; cin >> n;
  int m = 2*n-2;
  string a; cin >> a;
  if (a[0]=='S' && a[m-1]=='E') { cout << string(n-1,'E') << string(n-1,'S') << endl; return; }
  if (a[0]=='E' && a[m-1]=='S') { cout << string(n-1,'S') << string(n-1,'E') << endl; return; }
  if (a[0]=='S') {
    int k = 0;
    for (int i = 1; i < m; i++) {
      if (a[i]=='E') {
        if (a[i-1]=='E') break;
        k++;
      }
    }
    cout << string(k,'E') << string(n-1,'S') + string(m-n+1-k,'E') << endl;
  }
  else {
    int k = 0;
    for (int i = 1; i < m; i++) {
      if (a[i]=='S') {
        if (a[i-1]=='S') break;
        k++;
      }
    }
    cout << string(k,'S') << string(n-1,'E') + string(m-n+1-k,'S') << endl;
  }
}

int main() {
  //	setbuf(stdout, NULL);
 	cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}