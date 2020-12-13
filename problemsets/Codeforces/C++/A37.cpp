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
  int total = 0, height = 0, c = 0;
  for (int i = 0; i < n; i++) {
    c++;
    if (i < n-1 && a[i]==a[i+1]) continue;
    height = max(height, c);
    total++; c = 0;
  }
  cout << height << " " << total;
}
