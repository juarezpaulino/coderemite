/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y; x--;
    if (x > 0) a[x-1] += y-1;
    if (x < n-1) a[x+1] += a[x]-y;
    a[x] = 0;
  }
  for (int &u: a) cout << u << endl;
}
