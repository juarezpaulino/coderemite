/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s; cin >> n >> s; s--;
  vector<int> a[2] = {vector<int>(n),vector<int>(n)};
  for (int &u: a[0]) cin >> u;
  for (int &u: a[1]) cin >> u;
  bool ok = 0;
  int p = 0, d = 0;
  if (a[0][0]) while (p < n) {
    if (d==1 && p<s) break;
    if (p==s && a[d][s]) { ok = 1; break; }
    if (d==0 && p>s && a[1][p] && a[0][p]) d = 1;
    p += (d) ? -1 : 1;
  }
  cout << (ok?"YES":"NO");
}
