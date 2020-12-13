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
  set<int> u;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x) u.insert(x);
  }
  cout << u.size();
}
