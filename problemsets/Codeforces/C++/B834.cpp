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
  vector<int> c(256,0);
  string a; cin >> a;
  for (char &u: a) c[u]++;
  bool ok = 1;
  set<char> in;
  for (char &u: a) {
    in.insert(u); ok = ok && in.size() <= k;
    if (--c[u]==0) in.erase(u);
  }
  cout << (ok?"NO":"YES");
}
