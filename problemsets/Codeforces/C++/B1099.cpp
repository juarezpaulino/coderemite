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
  int s = sqrt(n+.5);
  int r = n-s*s, d = (s+1)*(s+1) - s*s;
  cout << s*2 + (!r ? 0 : r <= d/2 ? 1 : 2);
}
