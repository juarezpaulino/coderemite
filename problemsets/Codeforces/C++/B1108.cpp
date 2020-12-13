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
  vector<int> a(n); for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  int x = a[n-1], y = a[n-2];
  if (x != y) for (int i = n-1; i >= 0; i--) {
    if (x%a[i] || (i && a[i]==a[i-1])) { y = a[i]; break; }
  }
  cout << x << " " << y;
}
