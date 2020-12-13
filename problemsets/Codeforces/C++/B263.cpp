/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n); for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  if (k > n) cout << -1;
  else cout << a[n-k] << " " << a[n-k];
}
