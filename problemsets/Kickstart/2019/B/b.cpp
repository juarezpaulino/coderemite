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

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void solve() {
  int n; cin >> n;
  int a = 0, s, e, l;
  vi S, E, L;
  for (int i = 0; i < n; i++) {
    cin >> s >> e >> l;
    if (l == 0) a += e;
    else S.eb(s), E.eb(e), L.eb(l);
  }
  int ret = 0, n = sz(S);
  for (int k = 0; k < n; k++) {
    int u = k, v = E[k];
    int used[110] = {0};
    used[k] = 1;
  	for (int t = S[0]; t < n*S[0]; t+=S[0]) {
  	  int best = INT_MIN, l;
      for (int i = 0; i < n; i++) if (!used[i]) {
        int c = E[i]-L[i]*t;
        if (c > best) best = c, l = i;
      }
      if (best < 0) break;
      v += best; used[l] = 1;
  	}
  	ret = max(ret, v);
  }
  cout << ret+a << endl;
}

int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}