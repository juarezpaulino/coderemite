/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  int ret = 0, l = 0, c = 0;
  while (n--) {
    cin >> x;
    if (x > c) l++, ret = max(ret, l);
    else l = 1;
    c = x;
  }
  cout << ret;
}
