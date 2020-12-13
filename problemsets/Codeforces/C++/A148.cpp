/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[4], d;
  for (int i = 0; i < 4; i++) cin >> a[i];
  cin >> d;
  auto mmc = [](int u, int v){ return u*v/__gcd(u,v); };
  int ret = 0;
  for (int i = 1; i < 1<<4; i++) {
    int u = 1, c = 0;
    for (int j = 0; j < 4; j++) if (i&(1<<j)) c++, u = mmc(u, a[j]);
    ret += (c%2?1:-1) * d/u;
  }
  cout << ret;
}
