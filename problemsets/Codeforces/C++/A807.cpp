/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, p = 10000;
  cin >> n;
  bool unrated = 0;
  while (n--) {
    cin >> a >> b;
    if (a != b) { cout << "rated"; return 0; }
    if (p < b) unrated = 1;
    p = b;
  }
  cout << (unrated?"unrated":"maybe");
}
