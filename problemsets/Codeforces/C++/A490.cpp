/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  vector<vector<int>> a(4, vector<int>());
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[x].emplace_back(i);
  }
  int ret = min(a[1].size(), min(a[2].size(),a[3].size()));
  cout << ret << endl;
  for (int i = 0; i < ret; i++) cout << a[1][i] << " " << a[2][i] << " " << a[3][i] << endl;
}
