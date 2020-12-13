/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  cout << (s - accumulate(begin(a), end(a), 0) + *max_element(begin(a), end(a)) >= 0 ? "YES" : "NO");
}
