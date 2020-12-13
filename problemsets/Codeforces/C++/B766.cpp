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
  for (int i = 0; i < n-2; i++)
    if (a[i]+a[i+1] > a[i+2]) {
      cout << "YES";
      return 0;
    }
  cout << "NO";
}
