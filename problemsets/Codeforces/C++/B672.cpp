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
  string a; cin >> a;
  sort(begin(a), end(a));
  a.resize(unique(begin(a), end(a)) - begin(a));
  cout << (n > 26 ? -1 : n-(int)a.size());
}
