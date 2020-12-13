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
  int m = *min_element(begin(a), end(a));
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    if (a[i]%k != m%k) { cout << "-1"; return 0; }
    ret += (a[i]-m)/k;
  }
  cout << ret;
}
