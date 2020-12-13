/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> r(n); for (int &u: r) cin >> u;
  sort(begin(r), end(r), greater<int>());
  double ret = 0;
  for (int i = 0; i < n; i++) {
    ret += (i%2?-1:1) * r[i]*r[i] * M_PI;
  }
  cout << setprecision(9) << fixed << ret;
}
