/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a(5);
  int c[110] = {0};
  for (int &u: a) cin >> u, c[u]++;
  int v = 0;
  for (int &u: a) if (c[u] > 1) v = max(v,min(3,c[u])*u);
  cout << accumulate(begin(a), end(a), 0) - v;
}
