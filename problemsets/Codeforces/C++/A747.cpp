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
  for (int i = sqrt(n+1); i >= 0; i--) if (i*(n/i) == n) {
    cout << i << " " << n/i;
    return 0;
  }
}
