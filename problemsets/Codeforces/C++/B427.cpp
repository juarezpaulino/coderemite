/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, c; cin >> n >> t >> c;
  vector<int> a(n); for (int &u: a) cin >> u;
  int s = 0, ret = 0;
  for (int i = 0; i < n; i++) {
    s = (a[i] <= t) ? s+1 : 0;
    if (s == c) ret++, s--;
  } 
  cout << ret;
}
