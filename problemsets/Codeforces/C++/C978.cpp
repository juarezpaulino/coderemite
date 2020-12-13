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
  vector<long long> a(n+1), s(n+1,0);
  for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1]+a[i];
  while (m--) {
    long long x; cin >> x;
    int p = lower_bound(begin(s), end(s), x) - begin(s);
    cout << p << " " << x-s[p-1] << endl;
  }
}
