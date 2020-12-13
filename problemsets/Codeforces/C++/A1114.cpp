/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  if (a < x || a+b-x < y || a+b+c-x-y < z) cout << "NO";
  else cout << "YES";
}
