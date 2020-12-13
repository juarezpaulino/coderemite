/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int nA, nB; cin >> nA >> nB;
  int k, m; cin >> k >> m;
  int u, v;
  for (int i = 1; i <= nA; i++) { cin >> v; if (i == k) u = v; }
  for (int i = 0; i <= nB-m; i++) cin >> v;
  cout << (u < v ? "YES" : "NO");  
}
