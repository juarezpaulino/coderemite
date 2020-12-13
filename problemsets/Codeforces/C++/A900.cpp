/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x, y, plusX = 0, minusX = 0;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    if (x > 0) plusX++;
    else minusX++;
  }
  cout << ((minusX<2 || plusX<2) ? "Yes" : "No");
}
