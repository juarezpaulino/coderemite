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

int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  vector<pii> adj[n+1];
  for (int i = 0; i < m; i++) {
    int u, v, l; cin >> u >> v >> l;
    adj[u].eb(mp(v,l));
    adj[v].eb(mp(u,l));
  }
  vi flour(n+1,0);
  while (k--) {
    int u; cin >> u;
    flour[u] = 1;
  }
  int ret = -1;
  for (int u = 1; u <= n; u++) if (flour[u])
    for (auto v: adj[u]) if (!flour[v.fi] && (ret == -1 || v.se < ret))
      ret = v.se;
  cout << ret;
}