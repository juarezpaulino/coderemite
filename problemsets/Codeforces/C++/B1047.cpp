/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ret = 0, x, y;
  cin >> n;
  while (n--) cin >> x >> y, ret = max(ret, x+y);
  cout << ret;
}
