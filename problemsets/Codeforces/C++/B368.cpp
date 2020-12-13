/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  vector<int> a(n); for (int &u: a) cin >> u;
  vector<int> dp(n, 0);
  set<int> s;
  for (int i = n-1; i >= 0; i--) s.insert(a[i]), dp[i] = s.size();
  while (m--) {
    int x; cin >> x;
    cout << dp[x-1] << endl;
  }
}
