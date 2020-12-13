/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, l = 0, ret = 0, u = -1, x;
  cin >> n;
  while (n--) {
    cin >> x;
    if (x >= u) l++, ret = max(ret, l);
    else l = 1; 
    u = x;
  }
  cout << ret;
}
