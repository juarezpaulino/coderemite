/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, q;
  cin >> n;
  vector<long long> a(n);
  for (long long &u: a) cin >> u;
  sort(begin(a), end(a), greater<long long>());
  long long t = accumulate(begin(a), end(a), 0LL);
  cin >> m;
  while (m--) {
    cin >> q;
    cout << t-a[q-1] << endl;
  }
}
