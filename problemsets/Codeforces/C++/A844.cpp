/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  string a; cin >> a;
  set<char> u;
  for (char &c: a) u.insert(c);
  int n = a.size(), k, m = u.size(); cin >> k;
  if (k > n) cout << "impossible";
  else cout << max(0, k-m);
}
