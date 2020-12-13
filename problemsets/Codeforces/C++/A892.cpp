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
  long long s = 0;
  cin >> n;
  vector<int> b(n);
  for (int &u: b) cin >> x, s += x;
  for (int &u: b) cin >> u;
  sort(begin(b), end(b), greater<int>());
  cout << (s <= b[0]+b[1] ? "YES" : "NO");
}
