/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m = 1E8, ret = 0;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (b < m) m = b;
    ret += a*m;
  }
  cout << ret;
}
