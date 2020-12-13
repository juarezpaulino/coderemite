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
  int n, m; cin >> n >> m;
  vi val(n+1); for (int i = 1; i <= n; i++) cin >> val[i];
  vector<vi> adj(n+1);
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].eb(v); adj[v].eb(u);
  }
  vi vis(n+1,0);
  ll ret = 0;
  function<int(int)> dfs = [&](int u) {
    int ret = val[u];
    vis[u] = 1;
    for (auto v: adj[u]) if (!vis[v]) {
      ret = min(ret, dfs(v));
    }
    return ret;
  };
  for (int i = 1; i <= n; i++) if (!vis[i]) ret += dfs(i);
  cout << ret;
}