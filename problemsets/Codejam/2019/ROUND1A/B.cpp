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

int n, m;

void solve() {
  int p[] = { 17, 16, 13, 11, 9, 7, 5 };
  n = min(n,7);
  int rem[18];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 18; j++) cout << p[i] << " \n"[j==17];
    vector<int> in(18);
    for (auto &u: in) {
      cin >> u;
      if (u == -1) exit(1);
    }
    rem[i] = accumulate(all(in),0) % p[i];
  }
  for (int j = 0; j <= m; j++) {
    bool ok = 1;
    for (int i = 0; ok && i < n; i++) if (j%p[i]!=rem[i]) ok = 0;
    if (ok) { cout << j << endl; break; }
  }
  int ret;
  cin >> ret;
  if (ret == -1) exit(1);
}

int main() {
  setbuf(stdout, NULL);
 	//cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t >> n >> m;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}