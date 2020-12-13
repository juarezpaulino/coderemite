/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m;
  int c = m;
  while (n--) {
    cin >> a;
    if (c > a) {
      cout << "0 ";
      c -= a;
      continue;
    }
    a -= c;
    cout << a/m+1 << " ";
    c = m - a%m;
  }
}
