/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x; cin >> n >> k;
  set<int> a;
  while (n--) cin >> x, a.insert(x);
  int sum = 0;
  for (auto &u: a) {
    if (!k) break; k--;
    cout << u-sum << endl;
    sum += u-sum;
  }
  while (k--) cout << "0\n";
}
