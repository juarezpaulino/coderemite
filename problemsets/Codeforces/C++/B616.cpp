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
  vector<vector<int>> a(n, vector<int>(m));
  int ret = 0;
  for (auto &u: a) {
    for (auto &v: u) cin >> v;
    ret = max(ret, *min_element(begin(u), end(u)));
  }
  cout << ret;
}
