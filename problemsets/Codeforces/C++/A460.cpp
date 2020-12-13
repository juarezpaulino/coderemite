/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, ret = 0, p = 0;
  cin >> n >> m;
  while (n) {
    ret += n;
    n = (ret-p)/m;
    p = ret/m*m;
  }
  cout << ret;
}
