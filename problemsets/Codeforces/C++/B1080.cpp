/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int d = r-l+1;
    if (d == 1) cout << (l%2 ? -l : l) << endl;
    else if (d % 2) cout << (r%2 ? d/2 - r : r - d/2) << endl;
    else cout << (r%2 ? -d/2 : d/2) << endl;
  }
}
