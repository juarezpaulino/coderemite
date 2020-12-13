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
  vector<int> a(n);
  if (k > 1) { cout << "Yes"; return 0; }
  for (int &u: a) cin >> u;
  int x; cin >> x;
  *find(begin(a), end(a), 0) = x;
  for (int i = 1; i < n; i++) if (a[i]<=a[i-1]) { cout << "Yes"; return 0; }
  cout << "No";
}
