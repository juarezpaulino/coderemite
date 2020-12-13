/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> p(n);
  auto dp = vector<int>(n,-2);
  for (int &u: p) cin >> u, u--;
  function<int(int,bool &)> dfs = [&](int u, bool &cycle) {
    int &ret = dp[u];
    if (ret >= 0) return ret;
    if (ret == -1) { cycle = 1; return ret = u; }
    ret = -1; cycle = 0;
    int c = dfs(p[u], cycle);
    if (ret==u) cycle = 0;
    else ret = cycle ? u : c;
    return ret;
  };
  bool c = 0;
  for (int i = 0; i < n; i++) cout << dfs(i,c)+1 << " ";
}
